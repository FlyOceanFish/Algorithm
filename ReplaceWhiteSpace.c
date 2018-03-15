//
//  ReplaceWhiteSpace.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/15.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

/*
 请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“we are happy”，则输出“we%20are%20happy”，并且时间复杂度为O(n)
 */
#include "ReplaceWhiteSpace.h"

int findSpace(char string[]);

void replacewhiteSpace(char string[],int length){
    int countSpace = findSpace(string);
    int originLength = length;
    int replacedLength = originLength-countSpace+countSpace*3;
    int originIndex = originLength-1;
    int replacedIndex = replacedLength-1;
    string[replacedLength]='\0';
    while (originIndex>0) {
        if (string[originIndex]==' ') {
            string[replacedIndex]='0';
            string[replacedIndex-1]='2';
            string[replacedIndex-2]='%';
            replacedIndex = replacedIndex-3;
        }else{
            string[replacedIndex]=string[originIndex];
            --replacedIndex;
        }
        --originIndex;
    }
}
int findSpace(char string[]){
    int i = 0;
    int count = 0;
    while (string[i]!='\0') {
        if (string[i] == ' ') {
            count++;
        }
        i++;
    }
    return count;
}
//******* 测试数据 *********
//char string[] = "we are happy";
//replacewhiteSpace(string,sizeof(string)/sizeof(string[0]));
