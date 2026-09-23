/*#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS

void initSnake(void);
void initFood(void);
void drawSnake(void);
void moveSnake(void);
void keyDown(void);
void drawFood(void);
void eatFood(void);
int  snakeDie(void);
void showGrade(void);
void pause(void);

struct BODY
{
    int X;
    int Y;
};

struct SNAKE
{
    struct BODY body[100];
    int size;
    char position;
    COLORREF color;
}snake;

struct FOOD
{
    int X;
    int Y;
    int eatgrade;
    int flag;
    COLORREF color;
}food;

//枚举方向
// 小键盘，键码值
enum movePosition{ right = 77, left = 75, down = 80, up = 72 };
//表示主窗口
HWND hwnd = NULL;

int main()
{
    hwnd = initgraph(640, 480);//设置窗口大小
    setbkcolor(WHITE);
    cleardevice();//如果颜色没变刷新一下
    initSnake();//初始蛇
    BeginBatchDraw();
    while (1)
    {
        cleardevice();
        if (food.flag == 0)
        {
            initFood();
        }
        drawFood();
        drawSnake();
        if (snakeDie())
        {
            break;
        }
        moveSnake();
        eatFood();
        showGrade();
        //只有按键的时候接受按键
        while(_kbhit())
        {
            pause();
            keyDown();
        }

        Sleep(100);
        FlushBatchDraw();
    }

    EndBatchDraw();
    MessageBox(NULL, _T("游戏结束"), _T("Game Over"), MB_OK);
    closegraph();
    system("pause");
    return 0;
}

void initSnake(void)
{
    snake.size = 3;

    snake.body[0].X =20;
    snake.body[0].Y = 0;

    snake.body[1].X = 10;
    snake.body[1].Y =0;

    snake.body[2].X = 0;
    snake.body[2].Y = 0;

    snake.position = right;

    snake.color = GREEN;
    food.flag = 0;
}

void drawSnake(void)
{
    for (int i = 1; i < snake.size; i++)
    {
        setlinecolor(BLACK);//矩形边框线的颜色为黑色
        setfillcolor(snake.color);//蛇的填充色
        fillrectangle(snake.body[i].X, snake.body[i].Y, snake.body[i].X + 10, snake.body[i].Y + 10);//画矩形
    }
   //蛇头的颜色
        setlinecolor(BLACK);//矩形边框线的颜色为黑色
        setfillcolor(BLACK);//蛇的填充色
        fillrectangle(snake.body[0].X, snake.body[0].Y, snake.body[0].X + 10, snake.body[0].Y + 10);//画矩形

}
void moveSnake(void)
{
    //除了第一节，后面每一节都是前面一节的坐标
    for (int i = snake.size - 1; i > 0; i--)
    {
        snake.body[i].X = snake.body[i - 1].X;
        snake.body[i].Y = snake.body[i - 1].Y;
    }
    //第一节的处理
    switch (snake.position)
    {
        case right:
            snake.body[0].X += 10;
            break;
        case left:
            snake.body[0].X -= 10;
            break;
        case down:
            snake.body[0].Y += 10;
            break;
        case up:
            snake.body[0].Y -= 10;
            break;
        default:
            break;

    }
}

void keyDown(void)
{
   char key=0;
   key = _getch();

   switch (key)
   {
   case right:
       if (snake.position != left)
           snake.position = right;
       break;
   case left:
       if (snake.position != right)
           snake.position = left;
       break;
   case down:
       if (snake.position != up)
           snake.position = down;
       break;
   case up:
       if (snake.position != down)
           snake.position = up;
       break;
   default:
       break;
   }

}
void initFood(void)
{
    food.X = rand() % 65*10;//生成随机数，拆开写防止蛇吃不到食物
    food.Y = rand() % 48*10;
    food.color = RGB(rand() % 255, rand() % 255, rand() % 255);
    food.flag = 1;

    //如果食物出现在蛇的身上,那就重新再生成
    for (int i = 0; i < snake.size; i++)
    {
        if (food.X == snake.body[i].X && food.Y == snake.body[i].Y)
        {
            initFood();
        }
    }

}

void drawFood(void)
{

    setlinecolor(BLACK);
    setfillcolor((RGB(rand() % 255, rand() % 255, rand() % 255)));
    fillrectangle(food.X, food.Y, food.X + 10, food.Y + 10);
}
void eatFood(void)
{
    //蛇身长度增加
    //生成新的食物
    //分数增加
    if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
    {
        snake.size++;
        snake.color = food.color;
        food.flag = 0;
        food.eatgrade += 10;
    }
}

//蛇死亡时，游戏结束
int snakeDie(void)
{
    if (snake.body[0].X > 640 || snake.body[0].X < 0 || snake.body[0].Y < 0 || snake.body[0].Y >480)
    {
        outtextxy(200, 200, "CAN YOU SEE THE WALL?");
        return 1;
    }
    for (int i = 1; i < snake.size; i++)
    {
        if (snake.body[0].X == snake.body[i].X
            && snake.body[0].Y == snake.body[i].Y)
        {
            outtextxy(200, 200, "YOU KILL YOURSELF!");
            return 1;
        }
    }
    return 0;
}

void showGrade(void)
{
    char grade[100] = "";
    sprintf_s(grade, "%d", food.eatgrade);
    setbkmode(TRANSPARENT);
    settextcolor(LIGHTBLUE);
    outtextxy(580-20, 20, "分数：");
    outtextxy(580 + 50-20, 20, grade);

}

void pause(void)
{
    if (_getch() == 32)
    {
        while (_getch() != 32)//停在这里
        {
        }
    }
}
*/
