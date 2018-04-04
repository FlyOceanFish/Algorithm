//  Created by FlyOceanFish on 2018/4/4.
//  Copyright © 2018年 FlyOceanFish. All rights reserved.
//

/*
 Given a string s, find the longest palindromic(回文正着读和倒着读都一样) substring in s. You may assume that the maximum length of s is 1000.
 */
#include "LongestPalindrome.h"
char* longestPalindrome(char* s) {
    char *go,*left,*right,*re;
    char *max_start = s;
    int max_length,temp_length;
    char *s_end;
    s_end = s+strlen(s);
    if (strlen(s) == 0) return s;
    if (strlen(s) == 1) return s;
    for(go = s,max_length = 1;go<s_end;)
    {
        if (s_end - go <= max_length * sizeof(char) / 2) break;
        left = go,right = go;
        while(*right==*(right+1)) right++;
        go = right + 1;
        printf("first left:%c\n",*(left-1));
        printf("first right:%c\n",*(right+1));
        while(left<s_end && left>s && *(left-1) == *(right+1))
        {
            printf("left:%c\n",*(left-1));
            printf("right:%c\n",*(right+1));
            right++;
            left--;
        }
        temp_length = (right-left)/sizeof(char) + 1;
        if(temp_length > max_length) {
            max_start = left;
            max_length = temp_length;
        }
    }
    re =(char *) malloc(max_length*sizeof(char)+1);
    go = re;
    while(max_length)
    {
        *(go) = *(max_start);
        go++;
        max_start++;
        max_length--;
    }
    *go = '\0';
    return re;
}
//******* 测试数据 *********
//char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//char *s2 = "abccccda";
//char * result = longestPalindrome(s2);
//printf("%s\n",result);

