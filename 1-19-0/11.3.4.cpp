/*
From:ITC
11
STL defects
11.3
"use auto pointer
"
11.3.4
Lambdas should not be used
*/
#include<iostream>
using namespace std;                                                                                                              
void func() {
    std::cout << ""Hello world"" << std::endl;
}
int use_auto_pointer_004() {
    func();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}