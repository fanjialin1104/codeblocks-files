/*
#include <stdio.h>
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}
int getMonthDays(int year, int month) {
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return month_days[month - 1];
}
int getDayOfYear(int year, int month, int day) {
    int total_days = 0;
    for (int i = 1; i < month; i++) {
        total_days += getMonthDays(year, i);
    }
    total_days += day;
    return total_days;
}
int main() {
    int year, month, day;
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    printf("请输入日期：");
    scanf("%d", &day);
    int day_of_year = getDayOfYear(year, month, day);
    printf("%d年%d月%d日是该年的第%d天\n", year, month, day, day_of_year);
    return 0;
}
*/
