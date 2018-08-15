//
//  SortAges.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/19.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 实现一个排序算法，时间复杂度为O(n)。可以使用辅助控件，排序的数据是年龄
 */
#include <stdio.h>

void sortAges(int ages[], int length){
    const int MAX_AGE =99;
    int timesOfAge[MAX_AGE+1];
    for (int i = 0; i<MAX_AGE; i++) {
        timesOfAge[i] = 0;
    }
    for (int i = 0; i<length; i++) {
        int age = ages[i];
        ++timesOfAge[age];//将年龄与index一一对应，同时存储了次数。此时其实已经排好序，接着再将数组展开即可完成排序
    }
    int index = 0;
    for (int i = 0; i<MAX_AGE; i++) {
        for (int j=0; j<timesOfAge[i]; j++) {
            ages[index] = i;
            index++;
        }
    }
}
//******* 测试数据 *********
//此算法是通过长度为100的整数数组作为辅助空间换来了O(n)的时间效率  
//int ages[] = {10,80,45,34,22,18,18,33,33,32};
//sortAges(ages, sizeof(ages)/sizeof(ages[0]));

