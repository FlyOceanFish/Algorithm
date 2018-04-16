//
//  Permutation.c
//  testcc
//
//  Created by FlyOceanFish on 2018/4/16.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba
 */
#include "Permutation.h"
void _permutation(char *pStr,char *pBegin);

void permutation(char *pStr){
    if (pStr == NULL) {
        return;
    }
    _permutation(pStr, pStr);
}

void _permutation(char *pStr,char *pBegin){
    if (*pBegin == '\0') {
        printf("%s\n",pStr);
    }else{
        for (char *pCh = pBegin; *pCh!='\0'; ++pCh) {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            _permutation(pStr, pBegin+1);
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}
//******* 测试数据 *********
//char s[] = "abc";
//permutation(s);

