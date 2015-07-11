//
//  countFactorialZeros.cpp
//  countZeros
//
//  Created by willard on 15/7/11.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

#include <iostream>
using namespace std;

extern int countFactorialZeros(int &N);
extern int countFactorialZeros1(int &N);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int N = 100;
    int count = countFactorialZeros(N);
    cout << "Zero numbers by countZeros: " << count << endl;
    int count1 = countFactorialZeros1(N);
    cout << "Zero numbers by countZeros1: " << count1 << endl;
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
