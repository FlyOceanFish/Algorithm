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
#include <_ctype.h>

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
int jump(int* nums, int numsSize) {
    if(numsSize==1){
        return 0;
    }
    if ((numsSize==2&&nums[0]>=1)||(nums[0]>=numsSize-1)) {
        return 1;
    }
    int max = nums[0];
    int preMax = nums[0];
    int index = 0;
    for (int i = 2;i<numsSize;i++){
        for(int j=index+1;j<max+1;j++){
            int temp = j+nums[j];
            if (temp>=preMax){
                preMax = temp;
                index = j;
            }
            if(temp>=numsSize-1){
                return i;
            }
        }
        max = preMax;
    }
    return 0;
}
void reverse2(int start,int end,char *s)
{
    char temp;
    while(start<end){
        temp = s[end];
        s[end--]=s[start];
        s[start++]=temp;
    }
}
char* reverseStr(char* s, int k) {
    int len = strlen(s);
    if(len<k){
        reverse2(0,len-1,s);
        return s;
    }
    int rang = 0;
    int index = 0;
    while(rang<=len){
        int right = rang+k-1;
        
        if(right>len){
            right = len-1;
        }
        reverse2(rang,right,s);
        index++;
        rang = k*index*2;
    }
    return s;
}
void test(int i){
    i++;
    if (i>10) {
        return;
    }
    printf("** %d **\n",i);
    test(i);
    
    printf("我是结束** %d **\n",i);
}
//"mississippi"
//"issipi"
int strStr(char* haystack, char* needle) {
    if(haystack==NULL||needle==NULL)
        return -1;
    if (*needle=='\0') {
        return 0;
    }
    if (strlen(haystack)<strlen(needle)) {
        return -1;
    }
    char *tmp = needle;
    int index = -1;
    int result = -1;
    int indexTmp = index;
    char *haystacktmp = "";
    while(*haystack){
        index++;
        if(*haystack==*tmp){
            tmp++;
            if (result==-1) {
                result = index;
                haystacktmp = haystack;
                indexTmp = index;
            }
        }else{
            if (result!=-1) {
                result = -1;
                haystack = haystacktmp;
                index = indexTmp;
            }
            tmp = needle;
        }
        haystack++;
        if (*tmp=='\0') {
            return result;
        }
        if (*haystack=='\0'&&*tmp!='\0') {
            result = -1;
        }

    }
    return result;
}

int removeElement(int* nums, int numsSize, int val) {
    int length = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            nums[length++] = nums[i];
        }
    }
    return length;
}

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l1tmp = l1;
    struct ListNode *l2tmp = l2;
    while(l1tmp!=NULL){
        struct ListNode *pre = NULL;
        while (l2tmp!=NULL) {
            if (l1tmp->val<=l2tmp->val&&(l1tmp->next==NULL||l2tmp->val<=l1tmp->next->val)) {
                struct ListNode *tmp1 = l1tmp->next;
                struct ListNode *tmp2 = l2tmp->next;
                pre = l2tmp;
                l1tmp->next = l2tmp;
                l2tmp->next = tmp1;
                
                l2tmp = tmp2;
                continue;
            }else{
                l1tmp = pre;
                break;
            }
        }
        l1tmp = l1tmp->next;
    }
    if (l2tmp!=NULL) {
        l1tmp->next = l2tmp;
    }
    return l1;
}
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize<=0) {
        return 0;
    }
    int length = 0;
    int pre = INT16_MIN;
    for (int i = 0; i<numsSize; i++) {
        int tmp = nums[i];
        if (pre!=tmp) {
            pre = tmp;
            nums[length++] = tmp;
        }
    }
    return length;
}

bool isValid(char* s) {
    long len = strlen(s);
    if((len&1)==1) return false;
    
    long limit = len/2;
    char *stack = malloc(limit);
    int idx = 0;
    
    for(int i=0; i<len; ++i){
        char cur = s[i];
        if(cur=='(' || cur=='{' || cur=='['){
            if(idx == limit) return false;
            stack[idx++] = cur;
        }else{
            if(idx == 0) return false;
            if((cur == '}' && stack[idx-1] == '{') || (cur == ']' && stack[idx-1] == '[') || (cur == ')' && stack[idx-1] == '(')){
                idx--;
            }else{
                return false;
            }
        }
    }
    
    free(stack);
    return idx==0;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    int ii = 0, jj = 0;
    long minlen = 0;
    char c; // = strs[0][0];
    char* ans;

    minlen = strlen(strs[0]);
    for (ii = 1; ii < strsSize; ii++) {
        
        minlen = strlen(strs[ii]) < minlen ? strlen(strs[ii]) : minlen;
    }
    ans = (char*)malloc((minlen+1)*sizeof(char));
    memset(ans, 0x00, (minlen+1)*sizeof(char));
    for (ii = 0; ii < minlen; ii++) {
        c = strs[0][ii];
        for (jj = 1; jj < strsSize; jj++) {
            if (strs[jj][ii] != c)
                break;
        }
        if (jj != strsSize)
            return ans;
        
        ans[ii] = c;
    }
    return ans;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **result = malloc(sizeof(int)*numsSize);
    
    return result;
}

bool isLetter(char a){
    if(('a'<=a&&a<='z')||('A'<=a&&a<='Z'))
        return true;
    return false;
}
bool isNumber(char a){
    if ('0'<=a&&a<='9') {
        return true;
    }
    return false;
}
bool isPalindrome2(char* s) {
    long len = strlen(s);
    char *start = s;
    char *end = s+len-1;
    while(start<end){
        char a = *start;
        char b = *end;
        while(!isLetter(a)&&!isNumber(a)){
            if (start==s+len-1) {
                return true;
            }
            start++;
            a = *start;
        }
        while(!isLetter(b)&&!isNumber(b)){
            if (end==s) {
                return true;
            }
            end--;
            b = *end;
        }
        if (isLetter(a)&&isLetter(b)) {
            if((a==b)||(abs(b-a)==('a'-'A'))){
                start++;
                end--;
            }else{
                return false;
            }
        }else if (isNumber(a)&&isNumber(b)){
            if(a==b){
                start++;
                end--;
            }else{
                return false;
            }
        }else{
            return false;
        }

    }
    return true;
}
struct ListNode* reverseList(struct ListNode* head) {
    if(NULL==head||NULL==head->next) return head;
    
    struct ListNode *p=head->next;
    head->next=NULL;
    struct ListNode *newhead=reverseList(p);
    p->next=head;
    
    return newhead;
}

struct ListNode* reverseList2(struct ListNode* head) {
    if(NULL==head) return head;
    
    struct ListNode *p=head;
    p=head->next;
    head->next=NULL;
    while(NULL!=p){
        struct ListNode *ptmp=p->next;
        p->next=head;
        head=p;
        p=ptmp;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    struct ListNode l1 = {4,NULL};

    struct ListNode l2 = {3,&l1};

    struct ListNode l3 = {2,&l2};

    struct ListNode l4 = {1,&l3};
    struct ListNode *result = reverseList(&l4);
                                        
//    bool result = isPalindrome2("race a car");
//    printf("%d\n",result);
    
//    char *strs[3] = {"flower","flow","flight"};
//    char *result = longestCommonPrefix(strs, 3);
    
//    char *tmp = "(([()]){})";
//    bool result = isValid(tmp);
//    printf("%d\n",result);
//    int nums[] = {-1,0,0,0,0,3,3};
//    int result = removeDuplicates(nums, sizeof(nums)/sizeof(nums[0]));
//    printf("** %d ** \n",result);
//    struct ListNode l3 = {4,NULL};

//    struct ListNode l2 = {2,NULL};
//

//    mergeTwoLists(&l1, &l21);
    
//    printf("%d\n",l1.next->val);
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
//    int nums[] = {0,1,2};
//    int *result = countSmaller(nums, 3, NULL);
//    while (*result) {
//        printf("%d--\n",*result);
//        result++;
//    }
//    int nums[] = {2,3,1,1,4};
//    int jumps = jump(nums, sizeof(nums)/sizeof(nums[0]));
//    printf("%d--\n",jumps);
    return 0;
}


