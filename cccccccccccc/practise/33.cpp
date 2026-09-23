#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 初始化随机数种子，确保每次运行炸弹数字不同
    srand((unsigned int)time(NULL));
    // 随机生成1~100的炸弹数字
    int bomb = rand() % 100 + 1;
    int guess;  // 存储玩家猜测的数字
    printf("===== 数字炸弹游戏 =====\n");
    printf("规则：炸弹数字在1~100之间，猜到即触发炸弹！\n");
    printf("游戏开始，请输入第一个玩家的猜测数字：\n");

    while (1) {  // 无限循环，直到猜到炸弹
        scanf("%d", &guess);  // 获取玩家输入

        // 输入合法性判断（仅1~100）
        if (guess < 1 || guess > 100) {
            printf("输入无效！请输入1~100之间的整数：\n");
            continue;
        }

        // 猜数判断逻辑
        if (guess > bomb) {
            printf("数字大了！下一位玩家继续猜：\n");
        } else if (guess < bomb) {
            printf("数字小了！下一位玩家继续猜：\n");
        } else {
            printf("💥 炸弹触发！你猜到了炸弹数字%d，游戏结束！\n", bomb);
            break;  // 跳出循环，结束游戏
        }
    }
    return 0;
}
