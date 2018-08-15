//
//  FindInPartiallySortedMatrix.c
//  testcc
//
//  Created by FlyOceanFish on 2018/3/14.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

#include "FindInPartiallySortedMatrix.h"

bool find(int *martrix,int rows,int columns,int num){
    int row = 0;
    int column = columns-1;
    if (martrix==NULL||rows<0||column<1) {
        return false;
    }
    while (row<rows&&column<columns) {
        if (martrix[row*columns+column]==num) {
            return true;
        }else if (martrix[row*columns+column]<num){
            ++row;
        }else{
            --column;
        }
    }

    return false;
}
// **** 测试代码 ****
//int a[][4] = {{1,2,3,4},{5,6,9,10},{7,12,18,20},{9,13,19,30}};
//bool isfind = find(null, 4, 4, 19);//将二位数组强制转换成一维数组
//printf("%d\n",isfind);

