//
//  FirstNotRepeatingChar.c
//  testcc
//
//  Created by FlyOceanFish on 2018/5/28.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 在字符串中找出第一个只出现一次的字符。如输入"abaccdeff",则输出b
 */
#include "FirstNotRepeatingChar.h"
char firstNotRepeatingChar(char * pString){
    if (pString=='\0') {
        return '\0';
    }
    const int tableSize = 256;
    int hashTable[tableSize];
    for (int i = 0; i<tableSize; i++) {
        hashTable[i]=0;
    }
    char *pHashkey = pString;
    while (*(pHashkey)!='\0') {
        hashTable[*(pHashkey++)]++;
    }
    pHashkey = pString;
    while (*pHashkey!='0') {
        if (hashTable[*pHashkey]==1) {
            return *pHashkey;
        }
        pHashkey++;
    }
    return '\0';
}
//******* 测试数据 *********
//char *str = "abcddddskdafksjf";
//char temp = firstNotRepeatingChar(str);
//printf("%c\n",temp);//打印出b
