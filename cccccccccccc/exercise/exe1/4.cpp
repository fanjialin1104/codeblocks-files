#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int secretNum,guess,attempts=0;
    srand((unsigned int)time(NULL));
    secretNum=rand()%100+1;
    printf("=====猜字游戏====\n");
    printf("请猜一个1-100之间的数字，看看你能猜几次！\n");
    do{
        printf("请输入你的猜测");
        scanf("%d",&guess);
        attempts++;
        if(guess>secretNum)
        {
            printf("猜大了！再试试~\n");
        }
        else if(guess<secretNum)
        {
            printf("猜小了！再试试~\n");
        }
        else
        {
            printf("恭喜你！猜对了！你用了%d次尝试。\n",attempts);
        }
    }
    while(guess!=secretNum);
    return 0;
}
