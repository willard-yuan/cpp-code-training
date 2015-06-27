//
//  main.cpp
//  remove-duplicates-from-sorted-list
//
//  Created by willard on 15/6/27.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

/**
 Problem 26:
 Given a sorted array, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index+1;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A = {1, 2, 3, 3};
    Solution solver;
    int len = solver.removeDuplicates(A);
    cout<< len << endl;
    return 0;
}

