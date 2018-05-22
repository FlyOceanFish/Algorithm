//
//  GetuglyNumbers.c
//  testcc
//
//  Created by FlyOceanFish on 2018/5/22.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
我们把只包含因子2、3和5的数称作丑数。求按从小到大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7.习惯上我们把1当做第一个丑数
 */
#include "GetuglyNumbers.h"
#include <stdlib.h>

int minNumber(int number1,int number2,int number3){
    int min = (number1<number2)?number1:number2;
    min = (min <number3)?min:number3;
    return min;
}

int getUglyNumber(int index){
    if (index<=0) {
        return 0;
    }
    int *pUglyNumbers = malloc(index*sizeof(int));
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
    int *pMutiply2 = pUglyNumbers;
    int *pMutiply3 = pUglyNumbers;
    int *pMutiply5 = pUglyNumbers;
    while (nextUglyIndex<index) {
        int min = minNumber(*pMutiply2 * 2, *pMutiply3 * 3, *pMutiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;
        while (*pMutiply2*2<=pUglyNumbers[nextUglyIndex]) {
            ++pMutiply2;
        }
        while (*pMutiply3*3<=pUglyNumbers[nextUglyIndex]) {
            ++pMutiply3;
        }
        while (*pMutiply5*5<=pUglyNumbers[nextUglyIndex]) {
            ++pMutiply5;
        }
        ++nextUglyIndex;
    }
    int ugly = pUglyNumbers[nextUglyIndex-1];
    free(pUglyNumbers);
    return ugly;
}
//******* 测试数据 *********
//int number = getUglyNumber(10);
//printf("%d\n",number);//打印12
