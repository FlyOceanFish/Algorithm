//
//  Print1ToMaxOfNumber.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/26.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

#include "Print1ToMaxOfNumber.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 数组数字你，按顺序打印出从1到最大n位十进制数。比如输入3，则打印出1、2、3...999
 */
bool increment(char *number){
    int nLength = (int)strlen(number);
    bool flag = false;
    for (int i = nLength-1; i>=0; i--) {
        int nSum = number[i]-'0';
        nSum += 1;
        if (nSum>=10) {
            if (i==0) {
                flag = true;
            }
            number[i]='0';
        }else{
            number[i] = nSum+'0';
            break;
        }
    }
    return flag;
}
void printNumber(char *number){
    int flag = false;
    for (int i = 0;i<strlen(number); i++) {
        if (number[i]-'0'!=0) {
            flag = true;
        }
        if (flag) {
             printf("%c",number[i]);
        }
    }
    printf("\n");
}
void print1ToMaxOfNumber(int n){
    char *number = calloc(n+1, sizeof(char));
    number[n] = '\0';
    memset(number,'0',n);
    while (!increment(number)) {
        printNumber(number);
    }
}
//******* 测试数据 *********
//printf("%d\n",number2Of1(-10));
//print1ToMaxOfNumber(3);

