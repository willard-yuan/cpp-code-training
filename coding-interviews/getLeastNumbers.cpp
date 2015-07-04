//
//  main.cpp
//  getLeastNumbers
//
//  Created by willard on 15/7/4.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef multiset<int, greater<int> > itSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void getLeastNumbers(const vector<int> &data, itSet &leastNumbers, int k){
    leastNumbers.clear();
    if(k < 1 || data.size() < k) return;
    for(vector<int>::const_iterator iter = data.begin(); iter != data.end(); iter++){
        if(leastNumbers.size() < k){
            leastNumbers.insert(*iter);
        }else{
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter < *iterGreatest){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int A[] = {2, 1, 4, 2, 5, 1, 6, 9, 3, 4};
    vector<int> dataset(A, A+10);
    itSet leastNumbersSet;
    int k = 5;
    
    getLeastNumbers(dataset, leastNumbersSet, k);
    
    for(setIterator i = leastNumbersSet.begin(); i != leastNumbersSet.end(); ++i)
        cout<< *i << " ";
    cout << endl;
    
    return 0;
}
