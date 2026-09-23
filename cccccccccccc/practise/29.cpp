/*
#include<stdio.h>
int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
int i, s = 0, (*p)[3]= a;
for(i = 0; i < 2; i++)
    s += *(*(p+i));
printf("%d",s);
}
*/
/*
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    if(N%5>3||N%5==0)
        printf("Drying in day %d",N);
    else
        printf("Fishing in day %d",N);
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int count=0,sum=0;
    for(int i=M;i<=N;i++)
    {
        int t=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
                t++;
        }
        if(t==0)
        {
            count++;
            sum+=i;
        }
    }
    printf("%d %d",count,sum);
    return 0;
}
*/
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_NUM 1000
int main() {
    char str[1001];
    int num_arr[MAX_NUM];
    int count = 0;
    char *p = str;
    int temp = 0;
    int in_num = 0;
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = '\0';
    while (*p != '\0') {
        if (isdigit(*p)) {
            temp = temp * 10 + (*p - '0');
            in_num = 1;
        } else {
            if (in_num) {
                num_arr[count++] = temp;
                temp = 0;
                in_num = 0;
            }
        }
        p++;
    }
    if (in_num) {
        num_arr[count++] = temp;
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", num_arr[i]);
    }
    printf("\n");
    return 0;
}
*/
/*
#include <stdio.h>

#define LEN 20
#define MAX_STUDENTS 100

struct student {
    char no[LEN];
    char name[LEN];
    float score1, score2, score3;
    float average;
};

void input(struct student s[], int n);
float average(struct student s[], int n);
float findMaxAverage(struct student s[], int n);
void printTopStudents(struct student s[], int n, float maxAvg);

int main() {

    struct student stu[MAX_STUDENTS];
    int n;

    scanf("%d", &n);
    input(stu, n);

    float classAver = average(stu, n);
    float maxAver = findMaxAverage(stu, n);

    printf("%.2f\n", classAver);

    printTopStudents(stu, n, maxAver);

    return 0;
}

void input(struct student s[], int n) {
    for (int i = 0; i < n; i++) {

        scanf("%s %s %f %f %f", s[i].no, s[i].name, &s[i].score1, &s[i].score2, &s[i].score3);
        s[i].average = (s[i].score1 + s[i].score2 + s[i].score3) / 3.0f;
    }
}

float average(struct student s[], int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += s[i].average;
    }
    return sum / n;
}

float findMaxAverage(struct student s[], int n) {
    float maxAvg = s[0].average;
    for (int i = 1; i < n; i++) {
        if (s[i].average > maxAvg) {
            maxAvg = s[i].average;
        }
    }
    return maxAvg;
}

void printTopStudents(struct student s[], int n, float maxAvg) {
    for (int i = 0; i < n; i++) {
        if (s[i].average == maxAvg) {
            printf("%s %s %.2f %.2f %.2f\n",
                   s[i].no,
                   s[i].name,
                   s[i].score1,
                   s[i].score2,
                   s[i].score3);
        }
    }
}
*/
