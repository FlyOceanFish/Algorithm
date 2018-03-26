//
//  NumberOf1.c
//  testcc
//
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 实现一个函数，输入一个整数，输出该二进制表示中1的个数。例如把9表示成二进制是1001，有2位是1.因此输入9，该函数个数是2
 */
#include "NumberOf1.h"
int numberOf1(int n){//常规解法，避免是附属导致的死循环，所以左移flag
    int count = 0;
    int flag = 1;
    while (flag) {
        if (n&flag) {
            count++;
        }
        flag = flag<<1;
    }
    return count;
}
int number2Of1(int n){//高效解法，数字先减1再与原来的数字做位与运算，则会将数字最右边的1消除，变为0。比如1100，减1后位1011.1100|1011=1000
    int count = 0;
    while (n) {
        ++count;
        n= (n -1)&n;
    }
    return count;
}
//******* 测试数据 *********
//printf("%d\n",number2Of1(-10));

