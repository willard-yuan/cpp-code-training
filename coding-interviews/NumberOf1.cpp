//
//  main.cpp
//  NumberOf1
//
//  Created by willard on 15/6/30.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

#include <iostream>
using namespace std;

int NumberOf1_0(int n){
    int count = 0;
    while(n){
        ++ count;
        n = (n-1) & n;
    }
    return count;
}

int NumberOf1_1(int n){
    int count = 0;
    while(n){
        if(n & 1)
            ++ count;
        n = n >> 1;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int n = 16;
    int count1 = NumberOf1_1(n);
    
    cout << count1 << endl;
    
    return 0;
}
