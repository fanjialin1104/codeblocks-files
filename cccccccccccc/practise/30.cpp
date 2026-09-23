#include <stdio.h>
#include <string.h>
void sortStrings(char strs[5][20], int n) {
    char temp[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(strs[j], strs[j+1]) > 0) {
                strcpy(temp, strs[j]);
                strcpy(strs[j], strs[j+1]);
                strcpy(strs[j+1], temp);
            }
        }
    }
}
int main() {
    char strs[5][20];
    printf("请输入5个长度小于20的字符串：\n");
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个字符串：", i + 1);
        scanf("%s", strs[i]);
    }
    sortStrings(strs, 5);
    printf("\n按升序排序后的字符串为：\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", strs[i]);
    }
    return 0;
}
