//
//  MinInOrder.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/19.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 把一个数组最开始的若干元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出该旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小数为1.
 */
#include "MinInOrder.h"
static int min(int number[],int fontIndex,int rearIndex);
int minInOrder(int number[],int length){
    int fontIndex = 0;
    int rearIndex = length-1;
    int midIndex = 0;
    while (number[fontIndex]>=number[rearIndex]) {
        if (rearIndex-fontIndex==1) {
            midIndex = rearIndex;
            break;
        }
        midIndex = (fontIndex+rearIndex)/2;
        if (number[fontIndex]==number[rearIndex]&&number[fontIndex]==number[midIndex]) {//特殊案例{1,1,1,0,1,1}或{1,0,1,1,1,1}这种情况只能顺序查找
            return min(number, fontIndex, rearIndex);
        }
        if (number[midIndex]>=number[fontIndex]) {
            fontIndex = midIndex;
        }else{
            rearIndex = midIndex;
        }
    }
    return number[midIndex];
}
static int min(int number[],int fontIndex,int rearIndex){
    int result = number[fontIndex];
    for (int i = fontIndex+1; i<=rearIndex; i++) {
        if (result>number[i]) {
            result = number[i];
        }
    }
    return result;
}
//******* 测试数据 *********
//int numbers[] = {1,1,1,1,1,0,1};
//int numbers[] = {3,4,5,6,7,1,2};
//printf("%d\n",minInOrder(numbers, sizeof(numbers)/sizeof(numbers[0])));

