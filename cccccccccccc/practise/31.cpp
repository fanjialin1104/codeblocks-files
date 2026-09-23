/*#include<stdio.h>
#include<string.h>
typedef struct
{
    char id[20];
    char name[10];
    float score;
}Student;
int main()
{
    int n;
    Student students[10];


    float t;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       scanf("%s %s %f",students[i].id,students[i].name,&students[i].score);
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i+1;j++)
            if(students[j].score<students[j+1].score)
        {
            t=students[j].score;
            students[j].score=students[j+1].score;
            students[j+1].score=t;
        }
    printf("from highest to lowest:\n");
    for(int i=0;i<n;i++)
        printf("%s %s %.2f\n",students[i].id,students[i].name,students[i].score);
    printf("\n");
    printf("Information of students who failed:\n");
    for(int i=0;i<n;i++)
        if(students[i].score<60)
          printf("%s\n",students[i].name);
    printf("\n");
    printf("Information of students with scores below the average:\n");
    float sum=0;
    for(int i=0;i<n;i++)
        sum+=students[i].score;
    float x=sum/n;
    for(int i=0;i<n;i++)
        if(students[i].score<x)
          printf("%s %s %.2f\n",students[i].id,students[i].name,students[i].score);
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>

// 定义学生结构体
typedef struct {
    char id[20];      // 学号
    char name[20];    // 姓名
    float score;      // 成绩
} Student;

int main() {
    int n;
    Student students[10]; // 题目要求小于10，所以数组大小设为10足够
    Student temp;         // 用于排序交换

    // 1. 输入学生个数和学生信息
    if (scanf("%d", &n) != 1) return 0; // 防止无输入情况

    for (int i = 0; i < n; i++) {
        scanf("%s %s %f", students[i].id, students[i].name, &students[i].score);
    }

    // 2. 按成绩从高到低排序 (使用冒泡排序)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].score < students[j + 1].score) {
                // 交换
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // 3. 输出排序后的结果
    printf("from highest to lowest:\n");
    for (int i = 0; i < n; i++) {
        // 注意格式化输出，保留两位小数，且宽度对齐（参考样例）
        printf("%s %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }

    // 输出空行
    printf("\n");

    // 4. 输出不及格学生姓名 (成绩 < 60)
    printf("Information of students who failed:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].score < 60) {
            printf("%s\n", students[i].name);
        }
    }

    // 输出空行
    printf("\n");

    // 5. 输出低于平均分的学生记录
    // 先计算总分
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }
    float avg = sum / n;

    printf("Information of students with scores below the average:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].score < avg) {
            printf("%s %s %.2f\n", students[i].id, students[i].name, students[i].score);
        }
    }

    return 0;
}
*/
