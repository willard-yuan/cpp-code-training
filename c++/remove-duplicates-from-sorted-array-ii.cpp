//
//  main.cpp
//  remove-duplicates-from-sorted-array-ii
//
//  Created by willard on 15/6/27.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

/**
 Problem 80:
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array nums = [1,1,1,2,2,3],
 
 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (vector<int>::size_type i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index-2]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A = {1};
    Solution solver;
    int len = solver.removeDuplicates(A);
    cout<< len << endl;
    return 0;
}


