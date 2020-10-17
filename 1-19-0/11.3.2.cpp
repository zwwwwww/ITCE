/*
From:ITC
11
STL defects
11.3
"use auto pointer
"
11.3.2
" range based for loop or ""for_each"" should be perfered to traditional for loops"
*/
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;                                                                                                                                            
 void displayNumber(int i) {
    if (i > 0) {
        cout << "Positive number : " << i << endl;
    }
    else {
        cout << "Negative number : " << i << endl;
    }
}
int use_auto_pointer_002() {
    vector<int> v;
    for_each(v.begin(), v.end(), displayNumber);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/

    auto sum = 0;
    for (auto elt : v) {
        sum += elt;
    }
    return sum;
    // An even better way to write this would be:
     //return std::accumulate(v.begin(), v.end(), 0);
}
