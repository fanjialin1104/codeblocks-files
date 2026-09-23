/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// 游戏区域大小
#define WIDTH 20
#define HEIGHT 10
// 蛇的最大长度
#define MAX_LEN 50

// 方向枚举
enum Dir { UP, DOWN, LEFT, RIGHT };

// 蛇的结构体
typedef struct {
    int x[MAX_LEN];
    int y[MAX_LEN];
    int len;
    enum Dir dir;
} Snake;

// 食物结构体
typedef struct {
    int x;
    int y;
} Food;

// 全局变量
Snake snake;
Food food;
// 游戏地图（0=空，1=蛇身，2=食物）
int map[HEIGHT][WIDTH] = {0};

// 模拟清屏（手机端替代system("cls")）
void clearScreen() {
    // 输出大量换行，模拟清屏效果
    for (int i = 0; i < 50; i++)
        printf("\n");
}

// 初始化蛇
void initSnake() {
    snake.len = 3;
    snake.dir = RIGHT;
    // 初始位置在地图中间
    snake.x[0] = WIDTH / 2;
    snake.y[0] = HEIGHT / 2;
    for (int i = 1; i < snake.len; i++) {
        snake.x[i] = snake.x[0] - i;
        snake.y[i] = snake.y[0];
    }
}

// 生成食物（不与蛇身重叠）
void createFood() {
    srand((unsigned int)time(NULL));
    while (1) {
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
        // 检查是否和蛇身重叠
        int overlap = 0;
        for (int i = 0; i < snake.len; i++) {
            if (snake.x[i] == food.x && snake.y[i] == food.y) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) break;
    }
}

// 绘制游戏界面
void drawMap() {
    // 重置地图
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            map[i][j] = 0;

    // 标记蛇身
    for (int i = 0; i < snake.len; i++)
        map[snake.y[i]][snake.x[i]] = 1;

    // 标记食物
    map[food.y][food.x] = 2;

    // 绘制上边框
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");

    // 绘制内容区
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == 1) printf("■");  // 蛇身
            else if (map[i][j] == 2) printf("●"); // 食物
            else printf(" ");                  // 空白
        }
        printf("|\n");
    }

    // 绘制下边框
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");

    // 显示操作提示和得分
    printf("得分：%d | 操作：输入 w/s/a/d 后按回车控制方向 | 输入 q 退出\n", (snake.len - 3) * 10);
}

// 键盘控制方向（适配无_kbhit()的环境）
void controlDir() {
    char key;
    // 非阻塞读取（适配手机端）
    scanf("%c", &key);
    switch (key) {
        case 'w':
        case 'W':
            if (snake.dir != DOWN) snake.dir = UP;
            break;
        case 's':
        case 'S':
            if (snake.dir != UP) snake.dir = DOWN;
            break;
        case 'a':
        case 'A':
            if (snake.dir != RIGHT) snake.dir = LEFT;
            break;
        case 'd':
        case 'D':
            if (snake.dir != LEFT) snake.dir = RIGHT;
            break;
        case 'q':
        case 'Q':
            exit(0);
            break;
        default:
            // 按其他键不改变方向
            break;
    }
    // 清空输入缓冲区
    while (getchar() != '\n');
}

// 移动蛇
void moveSnake() {
    // 蛇身跟随头部
    for (int i = snake.len - 1; i > 0; i--) {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1];
    }

    // 头部移动
    switch (snake.dir) {
        case UP:    snake.y[0]--; break;
        case DOWN:  snake.y[0]++; break;
        case LEFT:  snake.x[0]--; break;
        case RIGHT: snake.x[0]++; break;
    }
}

// 碰撞检测
int checkCrash() {
    // 撞边界
    if (snake.x[0] < 0 || snake.x[0] >= WIDTH ||
        snake.y[0] < 0 || snake.y[0] >= HEIGHT)
        return 1;

    // 撞自己
    for (int i = 1; i < snake.len; i++) {
        if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
            return 1;
    }
    return 0;
}

// 吃食物逻辑
void eatFood() {
    if (snake.x[0] == food.x && snake.y[0] == food.y) {
        snake.len++;          // 蛇变长
        createFood();         // 生成新食物
    }
}

int main() {
    initSnake();     // 初始化蛇
    createFood();    // 生成初始食物

    while (1) {
        clearScreen();   // 清屏
        drawMap();       // 绘制界面
        controlDir();    // 检测按键（输入后按回车）
        moveSnake();     // 移动蛇
        eatFood();       // 检查是否吃食物

        // 碰撞则游戏结束
        if (checkCrash()) {
            clearScreen();
            printf("游戏结束！最终得分：%d\n", (snake.len - 3) * 10);
            break;
        }

        // 控制游戏速度（usleep是微秒，500000=0.5秒）
        usleep(500000);
    }
    return 0;
}
*/
