//
//  main.c
//  testcc
//
//  Created by FlyOceanFish on 2017/12/22.
//  Copyright © 2017年 FlyOceanFish. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FindInPartiallySortedMatrix.h"
#include "ReplaceWhiteSpace.h"
#include "SortAges.h"
#include "MinInOrder.h"
#include "Fibonacci.h"
#include "NumberOf1.h"
#include <math.h>
#include "Print1ToMaxOfNumber.h"
#include "ReOrderOddEven.h"
#include "LongestPalindrome.h"
#include "Permutation.h"
#include "FindGreatestSumOfSubArray.h"
#include "GetuglyNumbers.h"
#include "FirstNotRepeatingChar.h"
#include "GetNumberOfK.h"
#include "FindNumbersWithSum.h"
#include "ReverseSentence.h"

void out(){
    FILE *pfile = fopen("/Users/wangrifei/Desktop/a.text","w");
    char *name = "王日飞";
    fputs(name, pfile);
    fclose(pfile);
}
void in(){
    char input[10];
    fgets(input, 10, stdin);
    printf("你输入的是%s\n",input);
}
void sortMaoPao(){
    char *countries[]={
        "China",
        "American",
        "Italy",
        "France",
        "Spain",
        "Portugal",
        "Denmark",
        "Germany",
        "Australia",
        "New Zealand",
        "Singapore",
        "Thailand",
        "India",
        "Malaysia",
        "Indonesia",
    };
    //计算数组的长度
    int len = sizeof(countries)/sizeof(countries[0]);
    //冒泡排序
    for (int i = 0; i<len-1; i++) {
        for (int j = 0; j<len-1-i; j++) {
            int result = strcmp(countries[j], countries[j+1]);
            if (result<0) {//j+1大
                char *temp = countries[j];
                countries[j]=countries[j+1];
                countries[j+1] = temp;
            }
        }
    }
    for (int i = 0; i<len; i++) {
        printf("%s\n",countries[i]);
    }
}
//删除str中ch中的字符
void delChar(char* str,char* ch)
{
    char *p = str;
    char *q = str;
    char *del = ch;
    while(*q)
    {
        int tag = 0;
        while (*del) {
            if (*q ==*del)
            {
                tag = 1;
                break;
            }
            del++;
        }
        del = ch;
        if (tag==0) {
            *p = *q;
            p++;
        }
        q++;
    }
    *p='\0';
}
char str[] = "a dfkfdl kdfljjf jkfdjjl lfjdk jj   ";
char str2[] = "adf";

int StrToInt(char * string){
    int num = 0;
    while (*string!=0) {
        num = num*10+*string-'0';
        ++string;
    }
    return num;
}
void printa(int *matrix){
    printf("%d\n",matrix[10]);
}

int * twoSum(int* nums, int numsSize, int target) {
    int *result = (int *)malloc(2*sizeof(int));
    result[0]=result[1]=0;
    for (int i = 0;i<numsSize;i++){
        for (int j = i+1;j<numsSize;j++){
            if (nums[i]+nums[j]==target){
                result[0] = i;
                result[1] =j;
                break;
            }
        }
    }
    return result;
}
int lengthOfLongestSubstring(char* s)
{
    int len=0;
    char *end=s,*temp;
    char* addressTable[128]={NULL};
    while(*end){
        temp = addressTable[*end];
        addressTable[*end]=end;
        if(temp>=s){
            len=end-s>len?end-s:len;
            s = temp+1;
        }end++;
    }
    len=end-s>len?end-s:len;
    return len;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *num = calloc(nums1Size+nums2Size, sizeof(int));
    int *shortNums = nums1;
    int *longNums = nums2;
    int big = nums2Size;
    int small = nums1Size;
    if (nums1Size>nums2Size) {
        shortNums = nums2;
        longNums = nums1;
        big = nums1Size;
        small = nums2Size;
    }
    int numIndex = nums2Size+nums1Size-1;
    small = small-1;
    for (int i =big-1; i>=0; i--) {
        int tmp = shortNums[small];
        int tmp2 = longNums[i];
        if (tmp2>tmp) {
            num[numIndex] = tmp2;
            numIndex--;
        }else{
            while (shortNums[small]>tmp2&&small>=0) {
                num[numIndex] = shortNums[small];
                numIndex--;
                small--;
            }
             num[numIndex] = tmp2;
             numIndex--;
        }
    }
    if (small>=0) {
        for (int i = small; i>=0; i--) {
            num[numIndex] = shortNums[small];
            numIndex--;
            small--;
        }
    }
    for (int i =0; i<nums2Size+nums1Size; i++) {
        printf("%d\n",num[i]);
    }
    int mid = (int)(nums1Size+nums2Size)/2;
    if (((nums1Size+nums2Size)&1)) {
        return num[mid];
    }
    return (num[mid]+num[mid-1])/2.0;
}
int reverse(int x) {
    long long val = 0;
    do
    {
        val = val * 10 + x % 10;
        x /= 10;
    } while (x);
    
    return val;
}

char* convert(char* s, int numRows) {
//    char *result = calloc(strlen(s), sizeof(char));
    char *result = s;
    int index = 0;
    unsigned long length = strlen(s);
    for (int i = 0; i<numRows; i++) {
        int j = 0;
        while (true) {
            int num = 0;
            if (i!=0&&i!=numRows-1) {
                int j2 = (int)ceil(j/2.0);
                num = numRows*j2+(numRows-2)*j2+0;
                if ((j&0x1)==0) {//偶数
                    num = num+i;
                }else{
                    num = num-i;
                }
            }else{
               num = numRows*j+(numRows-2)*j+i;
            }
            if (num>=length) {
                j = 0;
                break;
            }
            result[index] = s[num];
            index++;
            j++;
        }
    }
    result[length]='\0';
    return result;
}
//char* convert2(char* s, int numRows) {
//int n=strlen(s);
//char* a;
//int k=0;
//if(numRows==1 || n<=numRows)return s;
//for(int i=0;i<numRows;i++)
//{
//    for(int j=i;j<n;j+=2*(numRows-1))
//    {
//        a[k++]=s[j];
//        if(i!=0 && i!=numRows-1)
//        {
//            int t=j+2*(numRows-1)-2*i;
//            if(t<n)
//                a[k++]=s[t];
//        }
//    }
//}
//a[k]='\0';
//return a;
//}
char s[] = "0123456789";
bool isPalindrome(int x) {
    int number = x;
    int number2 = 0;
    int result = 0;
    while(number){
        number2 = number%10;
        result = result*10+number2;
        number = number/10;
    }
    return result==x?true:false;
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ret = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        int count = 0;
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] < nums[i]){
                count++;
            }
        }
        ret[i] = count;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
//    isPalindrome(121);
//    char s[] = "abc";
//    permutation(s);
//    int nums[] = {1,-2,3,10,-4,7,2,-5};
//    int sum = FindGreatestSumOfSubArray(nums, sizeof(nums)/sizeof(nums[0]));
//    int number = getUglyNumber(3);
//    printf("%d\n",number);
//    char *str = "abcddddskdafksjf";
//    char temp = firstNotRepeatingChar(str);
//    printf("%c\n",temp);
//    int numbers[] = {2,2,5,5,5,5,7,8,10,23};
//    int count = getNumberOfK(numbers, sizeof(numbers)/sizeof(numbers[0]), 5);
//    printf("%d\n",count);
//    int data[] = {1,2,4,7,11,15};
//    int number1,number2;
//    bool found = findNumbersWithSum(data, sizeof(data)/sizeof(data[0]), 15, &number1, &number2);
//    if (found) {
//        printf("%d--%d\n",number1,number2);
//    }else{
//        printf("没有找到");
//    }
//    char str[] = "I am a Student";
//    char *temp = reverseSentence(str);
    int nums[] = {0,1,2};
    int *result = countSmaller(nums, 3, NULL);
    while (*result) {
        printf("%d--\n",*result);
        result++;
    }
    return 0;
}


