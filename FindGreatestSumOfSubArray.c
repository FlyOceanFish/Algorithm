//
//  FindGreatestSumOfSubArray.c
//  testcc
//
//  Created by FlyOceanFish on 2018/4/19.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

#include "FindGreatestSumOfSubArray.h"
/*
 输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个正数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
 */
int FindGreatestSumOfSubArray(int *pData,int nLength){
    if (pData==NULL||nLength<=0) {
        return 0;
    }
    int sum = 0;
    int currentSum = 0;
    for (int i = 0; i<nLength; i++) {
        int sumTmp = sum +pData[i];
        if (sumTmp>0) {
            sum = sumTmp;
            if (sum>currentSum) {
                currentSum = sum;
            }
        }else{
            sum = 0;
        }
    }
    return currentSum;
}
//******* 测试数据 *********
//int nums[] = {1,-2,3,10,-4,7,2,-5};
//int sum = FindGreatestSumOfSubArray(nums, sizeof(nums)/sizeof(nums[0]));

