//
//  FindNumbersWithSum.c
//  testcc
//
//  Created by FlyOceanFish on 2018/7/3.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得他们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
 例如输入数组{1,2,4,7,11,15}和数字15，则输出4和11
 */
#include "FindNumbersWithSum.h"
bool findNumbersWithSum(int data[],int length,int sum,int *num1,int *num2){
    bool found = false;
    if (length<1||num1==NULL||num2==NULL) {
        return found;
    }
    int ahead = length-1;
    int behind = 0;
    while (ahead>behind) {
        long long curSum = data[behind]+data[ahead];
        if (curSum==sum) {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }else if (curSum>sum){
            ahead--;
        }else{
            behind++;
        }
    }
    return found;
}
//******* 测试数据 *********
//int data[] = {1,2,4,7,11,15};
//int number1,number2;
//bool found = findNumbersWithSum(data, sizeof(data)/sizeof(data[0]), 15, &number1, &number2);
//if (found) {
//    printf("%d--%d\n",number1,number2);
//}else{
//    printf("没有找到");
//}
