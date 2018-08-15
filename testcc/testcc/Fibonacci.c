//
//  Fibonacci.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/19.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//
/*
 写一个函数，输入n,求斐波那契（Fibonacci）数列的第n项。斐波那契数列定义如下:
 f(n)=0  n=0;
 f(n)=1  n=1;
 f(n)=f(n-1)+f(n-2) n>1;
 */
#include "Fibonacci.h"
//这是递归，从上往下递归的走，如果数字比较大，非常的消耗时间，甚至会栈溢出
int fibonacci(int n){
    if (n==0) {
        return 0.0;
    }else if (n==1){
        return 1.0;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
//这个是从下往上递归的走，不过用的不是递归，时间复杂度为o(n)
double fibonacci2(int n){
    if (n<0) {
        return -1;
    }
    if (n==0) {
        return 0;
    }else if (n==1){
        return 1;
    }
    double a = 0;
    double b =1;
    for (int i = 2; i<n; i++) {
        double c = a+b;
        a = b;
        b = c;

    }
    return a+b;
}
//******* 测试数据 *********
//printf("%f\n",fibonacci2(300));

