#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// 游戏区域大小
#define WIDTH 40
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

// 方向枚举
typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direction;

// 点结构体
typedef struct {
    int x;
    int y;
} Point;

// 蛇结构体
typedef struct {
    Point body[MAX_SNAKE_LENGTH];
    int length;
    Direction direction;
} Snake;

// 食物结构体
typedef struct {
    Point position;
} Food;

// 全局变量
Snake snake;
Food food;
int score = 0;
int gameOver = 0;

// 函数声明
void initGame();
void drawGame();
void processInput();
void updateGame();
void generateFood();
int checkCollision();
int checkFood();
void gameOverScreen();

// 初始化游戏
void initGame() {
    // 初始化蛇
    snake.length = 3;
    snake.direction = RIGHT;

    // 蛇初始位置在屏幕中央
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2;

    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = startX - i;
        snake.body[i].y = startY;
    }

    // 初始化随机种子
    srand((unsigned)time(NULL));

    // 生成第一个食物
    generateFood();

    // 隐藏光标
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);
}

// 绘制游戏界面
void drawGame() {
    system("cls");  // 清屏

    // 绘制上边框
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // 绘制游戏区域
    for (int y = 0; y < HEIGHT; y++) {
        printf("#");  // 左边框

        for (int x = 0; x < WIDTH; x++) {
            int isSnake = 0;
            int isFood = 0;

            // 检查是否是蛇身
            for (int i = 0; i < snake.length; i++) {
                if (snake.body[i].x == x && snake.body[i].y == y) {
                    isSnake = 1;
                    if (i == 0) {
                        printf("O");  // 蛇头
                    } else {
                        printf("o");  // 蛇身
                    }
                    break;
                }
            }

            // 检查是否是食物
            if (!isSnake && food.position.x == x && food.position.y == y) {
                printf("*");  // 食物
                isFood = 1;
            }

            // 空白区域
            if (!isSnake && !isFood) {
                printf(" ");
            }
        }

        printf("#\n");  // 右边框
    }

    // 绘制下边框
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // 显示分数
    printf("Score: %d\n", score);
    printf("Controls: W(Up) A(Left) S(Down) D(Right)\n");
    printf("Press 'Q' to quit\n");
}

// 处理输入
void processInput() {
    if (_kbhit()) {
        char ch = _getch();

        switch (ch) {
            case 'w':
            case 'W':
                if (snake.direction != DOWN) snake.direction = UP;
                break;
            case 's':
            case 'S':
                if (snake.direction != UP) snake.direction = DOWN;
                break;
            case 'a':
            case 'A':
                if (snake.direction != RIGHT) snake.direction = LEFT;
                break;
            case 'd':
            case 'D':
                if (snake.direction != LEFT) snake.direction = RIGHT;
                break;
            case 'q':
            case 'Q':
                gameOver = 1;
                break;
        }
    }
}

// 更新游戏状态
void updateGame() {
    // 保存旧蛇头位置
    Point oldHead = snake.body[0];

    // 移动蛇身（从尾部向前移动）
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }

    // 根据方向移动蛇头
    switch (snake.direction) {
        case UP:
            snake.body[0].y--;
            break;
        case DOWN:
            snake.body[0].y++;
            break;
        case LEFT:
            snake.body[0].x--;
            break;
        case RIGHT:
            snake.body[0].x++;
            break;
    }

    // 检查是否吃到食物
    if (checkFood()) {
        // 增加蛇长度
        snake.length++;

        // 将新增的蛇身放在原尾部位置
        snake.body[snake.length - 1] = oldHead;

        // 增加分数
        score += 10;

        // 生成新食物
        generateFood();
    }

    // 检查碰撞
    if (checkCollision()) {
        gameOver = 1;
    }
}

// 生成食物
void generateFood() {
    int validPosition = 0;

    while (!validPosition) {
        validPosition = 1;

        // 随机生成食物位置
        food.position.x = rand() % WIDTH;
        food.position.y = rand() % HEIGHT;

        // 检查食物是否与蛇身重叠
        for (int i = 0; i < snake.length; i++) {
            if (snake.body[i].x == food.position.x &&
                snake.body[i].y == food.position.y) {
                validPosition = 0;
                break;
            }
        }
    }
}

// 检查碰撞
int checkCollision() {
    Point head = snake.body[0];

    // 检查是否撞墙
    if (head.x < 0 || head.x >= WIDTH ||
        head.y < 0 || head.y >= HEIGHT) {
        return 1;
    }

    // 检查是否撞到自己
    for (int i = 1; i < snake.length; i++) {
        if (head.x == snake.body[i].x &&
            head.y == snake.body[i].y) {
            return 1;
        }
    }

    return 0;
}

// 检查是否吃到食物
int checkFood() {
    Point head = snake.body[0];

    if (head.x == food.position.x &&
        head.y == food.position.y) {
        return 1;
    }

    return 0;
}

// 游戏结束画面
void gameOverScreen() {
    system("cls");
    printf("================================\n");
    printf("          GAME OVER!\n");
    printf("================================\n");
    printf("      Final Score: %d\n", score);
    printf("================================\n");
    printf("  Press any key to exit...\n");
    _getch();
}

// 主函数
int main() {
    // 初始化游戏
    initGame();

    // 游戏主循环
    while (!gameOver) {
        drawGame();
        processInput();
        updateGame();

        // 控制游戏速度（毫秒）
        Sleep(150);
    }

    // 显示游戏结束画面
    gameOverScreen();

    return 0;
}
