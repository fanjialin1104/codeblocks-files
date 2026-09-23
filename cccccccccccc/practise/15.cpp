
#include <conio.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 600    // 窗口宽度
#define HEIGHT 400   // 窗口高度
#define BLOCK_SIZE 20// 蛇身/食物块大小
#define MAX_LEN 100  // 蛇的最大长度

// 方向枚举
enum Direction { UP, DOWN, LEFT, RIGHT };

// 蛇的结构体
typedef struct {
    int x[MAX_LEN];  // 每节x坐标
    int y[MAX_LEN];  // 每节y坐标
    int len;         // 蛇长度
    enum Direction dir; // 移动方向
} Snake;

// 食物结构体
typedef struct {
    int x;
    int y;
    int exist; // 食物是否存在（1存在，0被吃）
} Food;

// 初始化蛇
void initSnake(Snake *snake) {
    snake->len = 3;          // 初始3节
    snake->dir = RIGHT;     // 初始向右

    // 初始位置（屏幕中间）
    snake->x[0] = WIDTH / 2;
    snake->y[0] = HEIGHT / 2;
    for (int i = 1; i < snake->len; i++) {
        snake->x[i] = snake->x[0] - i * BLOCK_SIZE;
        snake->y[i] = snake->y[0];
    }
}

// 初始化食物（随机位置，不与蛇身重叠）
void initFood(Food *food, Snake *snake) {
    srand((unsigned int)time(NULL)); // 随机种子
    while (1) {
        // 食物坐标必须是 BLOCK_SIZE 的整数倍（对齐网格）
        food->x = (rand() % (WIDTH / BLOCK_SIZE)) * BLOCK_SIZE;
        food->y = (rand() % (HEIGHT / BLOCK_SIZE)) * BLOCK_SIZE;

        // 检查是否与蛇身重叠
        int overlap = 0;
        for (int i = 0; i < snake->len; i++) {
            if (food->x == snake->x[i] && food->y == snake->y[i]) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) break;
    }
    food->exist = 1;
}

// 绘制蛇
void drawSnake(Snake *snake) {
    setfillcolor(GREEN); // 蛇身颜色
    for (int i = 0; i < snake->len; i++) {
        fillrectangle(
            snake->x[i], snake->y[i],
            snake->x[i] + BLOCK_SIZE, snake->y[i] + BLOCK_SIZE
        );
    }
}

// 绘制食物
void drawFood(Food *food) {
    setfillcolor(RED); // 食物颜色
    fillrectangle(
        food->x, food->y,
        food->x + BLOCK_SIZE, food->y + BLOCK_SIZE
    );
}

// 移动蛇
void moveSnake(Snake *snake) {
    // 后一节跟随前一节移动（从尾部开始）
    for (int i = snake->len - 1; i > 0; i--) {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }

    // 头部按方向移动
    switch (snake->dir) {
        case UP:    snake->y[0] -= BLOCK_SIZE; break;
        case DOWN:  snake->y[0] += BLOCK_SIZE; break;
        case LEFT:  snake->x[0] -= BLOCK_SIZE; break;
        case RIGHT: snake->x[0] += BLOCK_SIZE; break;
    }
}

// 键盘控制方向（防止反向掉头）
void keyControl(Snake *snake) {
    if (_kbhit()) { // 检测键盘输入
        switch (_getch()) {
            case 'w' | 'W' | 72: // 上（W键或方向键上）
                if (snake->dir != DOWN) snake->dir = UP;
                break;
            case 's' | 'S' | 80: // 下（S键或方向键下）
                if (snake->dir != UP) snake->dir = DOWN;
                break;
            case 'a' | 'A' | 75: // 左（A键或方向键左）
                if (snake->dir != RIGHT) snake->dir = LEFT;
                break;
            case 'd' | 'D' | 77: // 右（D键或方向键右）
                if (snake->dir != LEFT) snake->dir = RIGHT;
                break;
            case ' ': // 空格暂停/继续
                while (_getch() != ' ');
                break;
            case 'q' | 'Q': // Q键退出
                exit(0);
                break;
        }
    }
}

// 碰撞检测（边界+自身）
int collisionCheck(Snake *snake) {
    // 边界碰撞
    if (snake->x[0] < 0 || snake->x[0] >= WIDTH ||
        snake->y[0] < 0 || snake->y[0] >= HEIGHT) {
        return 1;
    }

    // 自身碰撞
    for (int i = 1; i < snake->len; i++) {
        if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
            return 1;
        }
    }
    return 0;
}

// 吃食物检测
void eatFoodCheck(Snake *snake, Food *food) {
    if (food->exist &&
        snake->x[0] == food->x && snake->y[0] == food->y) {
        snake->len++; // 蛇长度+1
        food->exist = 0; // 食物消失
        initFood(food, snake); // 重新生成食物
    }
}

// 显示分数
void showScore(int score) {
    char str[20];
    sprintf(str, "Score: %d", score);
    settextstyle(20, 0, "Arial"); // 字体大小和样式
    settextcolor(WHITE);
    outtextxy(10, 10, str); // 显示在左上角
}

int main() {
    initgraph(WIDTH, HEIGHT); // 创建图形窗口
    setbkcolor(BLACK); // 背景色黑色

    Snake snake;
    Food food;
    int score = 0;

    // 初始化
    initSnake(&snake);
    initFood(&food, &snake);

    while (1) {
        cleardevice(); // 清空屏幕（防止残影）

        // 绘制元素
        drawSnake(&snake);
        drawFood(&food);
        showScore(score);

        // 键盘控制
        keyControl(&snake);
            // 移动蛇
         moveSnake(&snake);

         // 碰撞检测（游戏结束）
         if (collisionCheck(&snake)) {
             settextstyle(40, 0, "Arial");
             settextcolor(RED);
             outtextxy(WIDTH/2 - 100, HEIGHT/2, "Game Over!");
             outtextxy(WIDTH/2 - 120, HEIGHT/2 + 50, "Press Q to exit");
             while (_getch() != 'q' && _getch() != 'Q');
             break;
         }

         // 吃食物检测
         eatFoodCheck(&snake, &food);
         score = snake->len - 3; // 初始3节，每吃一个食物+1分

         Sleep(150); // 控制移动速度（数值越小越快）
     }

     closegraph(); // 关闭图形窗口
     return 0;
 }
