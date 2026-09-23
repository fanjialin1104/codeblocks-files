/*#include <stdio.h>
int main()
{
    int votes[5] = {0};
    int invalid = 0;
    int num;
    printf("请输入选票（1-5为有效票，-1结束投票）：\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
            break;
        if (num >= 1 && num <= 5)
            votes[num - 1]++;
        else
            invalid++;
    }
    printf("\n===== 投票统计结果 =====\n");
    for (int i = 0; i < 5; i++)
        printf("候选人%d得票数：%d\n", i + 1, votes[i]);
    printf("废票数：%d\n", invalid);
    return 0;
}
*/
