//
//  main.cpp
//  p44
//
//  Created by willard on 15/6/28.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int reused = 100;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int sum = 0;
    for(int val = 1; val <= 100; val++)
        sum = sum + val;
    
    cout << reused << endl;
    
    reused = 10;
    cout << reused << endl; //局部覆盖全局
    
    cout << ::reused << endl;
    
    int ival = 1024;
    int &refVal = ival;
    refVal = 2048;
    cout << refVal << endl;
    
    int *p = &ival;
    cout << *p <<endl;
    
    return 0;
}