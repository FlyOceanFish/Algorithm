//
//  ReverseSentence.c
//  testcc
//
//  Created by FlyOceanFish on 2018/7/3.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 输入一个英文句子，翻转句子中的单词顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student.",则输出"student. am I"。
 */
#include "ReverseSentence.h"
void _reverse(char *pBegin,char *pEnd){
    if (pBegin==NULL||pEnd==NULL) {
        return;
    }
    while (pBegin<pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}
char *reverseSentence(char *pData){
    char *pBegin = pData;
    char *pEnd = pData;
    while (*pEnd!='\0') {
        pEnd++;
    }
    pEnd--;
    _reverse(pBegin, pEnd);
    pBegin = pEnd = pData;
    while (*pBegin!='\0') {
        if (*pBegin==' ') {
            pBegin++;
            pEnd++;
        }else if (*pEnd == ' '||*pEnd=='\0'){
            _reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }else{
            pEnd++;
        }
    }
    return pData;
}
//******* 测试数据 *********
//char str[] = "I am a Student";
//char *temp = reverseSentence(str);
