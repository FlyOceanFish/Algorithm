//
//  ReOrderOddEven.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/26.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
 */
#include "ReOrderOddEven.h"
void reOrderOddEven(int *pData,unsigned int length){
    int *pBegin = pData;
    int *pEnd = pData+length-1;
    while (pBegin<pEnd) {
        while (pBegin<pEnd&&(*pBegin&0x1)!=0) {//奇数
            pBegin++;
        }
        while (pBegin<pEnd&&(*pEnd&0x1)==0) {//偶数
            pEnd--;
        }
        int temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
    }
}
//******* 测试数据 *********
//int number[] = {1,2,3,4,5,6,4,3,4,56,7,8,33,22,121,42};
//reOrderOddEven(number, sizeof(number)/sizeof(number[0]));

