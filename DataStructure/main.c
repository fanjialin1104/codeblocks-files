#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100   // 顺序表最大容量

// 定义顺序表结构体
typedef struct{
    int data[MaxSize];
    int length;      // 当前实际元素个数
} SqList;

// 1. 初始化顺序表
void InitList(SqList *L){
    L->length = 0;
}

// 2. 按位插入：在第i个位置插入元素e（i从1开始）
int ListInsert(SqList *L, int i, int e){
    if(i < 1 || i > L->length + 1) return 0; // 位置非法
    if(L->length >= MaxSize) return 0;       // 表满
    // 元素后移
    for(int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
}

// 3. 按位删除：删除第i个位置元素，用e返回
int ListDelete(SqList *L, int i, int *e){
    if(i < 1 || i > L->length) return 0;
    *e = L->data[i-1];
    // 元素前移
    for(int j = i; j < L->length; j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}

// 4. 遍历打印顺序表
void PrintList(SqList *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main(){
    SqList L;
    InitList(&L);

    ListInsert(&L,1,10);
    ListInsert(&L,2,20);
    ListInsert(&L,3,30);
    printf("插入后：");
    PrintList(&L);

    int e;
    ListDelete(&L,2,&e);
    printf("删除的元素：%d\n",e);
    printf("删除后：");
    PrintList(&L);

    return 0;
}
