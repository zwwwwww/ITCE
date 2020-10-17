/*
From:ITC
15
Control flow defects
15.11
Premature nil termination argument
15.11.1
 object nil
*/
"#include<iostream>
using namespace std;                                                                                                          class Box
{
public:
    double length;  
    double breadth;  
    double height;   
};
void nil_001() {
    Box box1 = nil;  /*Tool should detect this line as error*/ /*ERROR: Control flow error*/
    cout << box1.length;
}"
