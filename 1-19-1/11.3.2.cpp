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

using namespace std; 
int use_auto_pointer_002() {
    vector<int> v;
    for (auto it = v.begin(); it != v.end(); ++it) { // /*Tool should detect this line as error*/ /*ERROR:STL error*/
        if (*it > 0) {
            cout << "Positive number : " << *it << endl;
        }
        else {
            cout << "Negative number : " << *it << endl;
        }
    }
    auto sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) { // /*Tool should detect this line as error*/ /*ERROR:STL error*/
        sum += *it;
    }
    return sum;
}
