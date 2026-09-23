#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
int main() {
    int n;
    char names[MAX_STUDENTS][20];
    float scores[MAX_STUDENTS];
    float temp_score;
    char temp_name[20];
    printf("请输入学生人数（1-%d）：", MAX_STUDENTS);
    while (scanf("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS) {
        printf("输入非法，请重新输入（1-%d）：", MAX_STUDENTS);
        while (getchar() != '\n');
    }
    printf("请输入%d名学生的姓名和平均成绩（格式：姓名 成绩）：\n", n);
    for (int i = 0; i < n; i++) {
        printf("学生%d：", i + 1);
        scanf("%s %f", names[i], &scores[i]);
        for (int j = 0; j < n - 1 - i; j++) {
            if (scores[j] < scores[j + 1]) {
                temp_score = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp_score;
                strcpy(temp_name, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp_name);
            }
        }
    }
    printf("\n===== 按成绩降序排序结果 =====\n");
    printf("排名\t姓名\t平均成绩\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", i + 1, names[i], scores[i]);
    }
    return 0;
}
