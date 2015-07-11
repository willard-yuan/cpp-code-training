//
//  main.cpp
//  countZeros
//
//  Created by willard on 15/7/11.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

extern int countFactorialZeros(int &N);
extern int countFactorialZeros1(int &N);
extern char *commonStrFind(const char *str, const char *substr);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    // 将阶乘结果计数
    int N = 10;
    int count = countFactorialZeros(N);
    cout << "Zero numbers by countZeros: " << count << endl;
    int count1 = countFactorialZeros1(N);
    cout << "Zero numbers by countZeros1: " << count1 << endl;
    
    const char *str = "deabc";
    const char *substr = "abc";
    string test = "hello world!";
    cout << test << endl;
    char *commonStr = commonStrFind(str, substr);
    cout << *commonStr << endl;
    
    return 0;
}

//统计因子法
int countFactorialZeros(int &N){
    int count = 0;
    for (int i = 1; i <= N; i++){
        int j = i;
        while(j % 5 == 0){
            ++count;
            j = j/5;
        }
    }
    return count;
}


//暴力解法
int countFactorialZeros1(int &N){
    int f = 1;
    int count = 0;
    if (N == 0) f = 1;
    for(int i = 1; i <= N; i++){
        f = f*i;
    }
    cout << N << "! : " << f <<endl;
    while(f%10 == 0){
        ++count;
        f = f/10;
    }
    return count;
}

char *commonStrFind(const char *str, const char *substr)
{
    if(str == NULL || substr == NULL) return NULL;
    if (*substr == '\0') return (char *)str;  //如果substr指向空字符串，则直接返回str所指得字符串
    
    const char *temp = substr;
    const char *p = NULL;
    
    while(*(str++) != '\0'){
        if(*str == *substr){
            p = str;  //记录第一个匹配字符的指针
            while(*substr != '\0'){  //判断是否与整个目标字符串匹配
                if(*(str++) != *(substr++)){  //若匹配过程不成功，则进行下一阶段扫描
                    substr = temp;  //substr回退到开始
                    str = p;   //str回退到p（第一个匹配字符的指针），进行下一次循环，str++
                    break;
                }
                if(*substr == '\0') return (char *)p;     //匹配成功
            }		
        }
    }
    return NULL;
}
