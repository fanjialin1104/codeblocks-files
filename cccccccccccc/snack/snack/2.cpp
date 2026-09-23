#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<stddef.h>

#define WIDE 60
#define HIGH 20

struct BODY
{
    int X;
    int Y;
};

struct SNAKE
{
    struct BODY body[WIDE*HIGH];
    int size;
}snake;

struct FOOD
{
    int X;
    int Y;
}food;

int score=0;

int kx=0;//用户按下awsd键所对应的坐标值
int ky=0;

int lastX=0;//蛇尾的坐标
int lastY=0;

int sleepSecond=300;

void initSnake(void);
void initFood(void);
void initUI(void);
void playGame(void);
void initWall(void);
void showScore(void);

int main()
{
   CONSOLE_CURSOR_INFO cci;//去除光标
   cci.dwSize=sizeof(cci);
   cci.bVisible=FALSE;//0假-不可见
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);//设置光标不可见生效

   initSnake();//初始蛇
   initFood();//初始食物

   initWall();
   initUI();//画蛇和食物

   playGame();//启动游戏

   showScore();
   system("pause");
    return EXIT_SUCCESS;
}



void showScore()
{
    //将光标移动到不影响游戏的地方
    COORD coord;
    coord.X=0;
    coord.Y=HIGH+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("Game Over!!!\n");
    printf("成绩为：%d\n\n\n",score);
}




//封装一个函数，定义初始化蛇
void initSnake(void)
{
    snake.size=2;

    snake.body[0].X=WIDE/2;
    snake.body[0].Y=HIGH/2;

    snake.body[1].X=WIDE/2;
    snake.body[1].Y=HIGH/2+1;

    return;
}

//初始化界面控件
void initUI(void)
{

    COORD coord={0};
     //画蛇
     for(size_t i=0;i<snake.size;i++)
     {
          coord.X=snake.body[i].X;
          coord.Y=snake.body[i].Y;
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
          if(i==0)
             putchar('H');
          else
            putchar('a');
     }
     //去除蛇尾
     coord.X=lastX;
     coord.Y=lastY;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
     putchar(' ');
    //画食物
    coord.X=food.X;
    coord.Y=food.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    putchar('#');
    //将光标移动到不影响游戏的地方
    coord.X=0;
    coord.Y=HIGH+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//定义初始化食物
void initFood(void)
{
    food.X=rand()%WIDE;
    food.Y=rand()%HIGH;

    return;
}

void initWall(void)
{
    for(size_t i=0;i<=HIGH;i++)//多行
    {
        for(size_t j=0;j<=WIDE;j++)
        {
            if(j==WIDE)
            {
                printf("|");
            }
            else if(i==HIGH)
            {
                printf("-");
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void playGame(void)
{
    char key='w';
    //判断蛇撞墙
    while(snake.body[0].X>=0&&snake.body[0].X<WIDE
        &&snake.body[0].Y>=0&&snake.body[0].Y<HIGH)
    {

        //更新蛇
        initUI();
        //接收用户按键输入
        if(_kbhit())
        {
            key=_getch();
        }

        switch(key)
        {
            case 'w':kx=0;ky=-1;break;
            case 's':kx=0;ky=+1;break;
            case 'd':kx=+1;ky=0;break;
            case 'a':kx=-1;ky=0;break;
            default:
                break;

        }

        //蛇撞身体:蛇头==任意一节身体
        for(size_t i=1;i<snake.size;i++)
        {
            if(snake.body[0].X==snake.body[i].X
            &&snake.body[0].Y==snake.body[i].Y)
            {
                return ;
            }
        }
        //蛇头撞食物
        if(snake.body[0].X==food.X&&snake.body[0].Y==food.Y)
        {
            //食物消失
            initFood();
            //身体增长
            snake.size++;
            //加分
            score+=10;
            //加速
            if(sleepSecond>=60)
            {
                 sleepSecond-=50;
            }

        }
        //记录蛇尾坐标
        lastX=snake.body[snake.size-1].X;
        lastY=snake.body[snake.size-1].Y;

        //蛇移动，前一节身体给后一节身体赋值
        for(size_t i=snake.size-1;i>0;i--)
        {
            snake.body[i].X=snake.body[i-1].X;
            snake.body[i].Y=snake.body[i-1].Y;
        }
        snake.body[0].X+=kx;
        snake.body[0].Y+=ky;

        Sleep(sleepSecond);

    }
}
