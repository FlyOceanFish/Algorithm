//
//  GetNumberOfK.c
//  testcc
//
//  Created by YTO on 2018/5/28.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

/*
 统计一个数字在排序数组中出现的次数。例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4.
 */
#include "GetNumberOfK.h"
int getFirstK(int *data,int length,int k,int start,int end);
int getLastK(int *data,int length,int k,int start,int end);

int getNumberOfK(int *data,int length,int k){
    int number = 0;
    if (data!=NULL&&length>0) {
        int first = getFirstK(data, length, k, 0, length-1);
        int last = getLastK(data, length, k, 0, length-1);
        if (first>-1&&last>-1) {
            number = last-first+1;
        }
    }
    return number;
}
int getFirstK(int *data,int length,int k,int start,int end){
    if (start>end) {
        return -1;
    }
    int middleIndex = (start+end)/2;
    int middle = data[middleIndex];
    if (middle==k) {
        if ((middleIndex>0&&data[middleIndex-1]!=k)||middleIndex==0) {
            return middleIndex;
        }else{
            end = middleIndex-1;
        }
    }else if (middle>k){
        end = middleIndex-1;
    }else{
        start = middleIndex+1;
    }
    return getFirstK(data, length, k, start, end);
}
int getLastK(int *data,int length,int k,int start,int end){
    if (start>end) {
        return -1;
    }
    int middleIndex = (start+end)/2;
    int middle = data[middleIndex];
    if (middle==k) {
        if ((middleIndex>0&&data[middleIndex+1]!=k)||middleIndex==length-1) {
            return middleIndex;
        }else{
            start = middleIndex+1;
        }
    }else if (middle>k){
        end = middleIndex-1;
    }else{
        start = middleIndex+1;
    }
    return getLastK(data, length, k, start, end);
}
//******* 测试数据 *********
//int numbers[] = {2,2,5,5,5,5,7,8,10,23};
//int count = getNumberOfK(numbers, sizeof(numbers)/sizeof(numbers[0]), 5);
//printf("%d\n",count);//输出4
