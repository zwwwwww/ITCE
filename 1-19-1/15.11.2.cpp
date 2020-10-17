/*
From:ITC
15
Control flow defects
15.11
Premature nil termination argument
15.11.2
class Nil
*/
"#include<iostream>
using namespace std;                                                                                                          class Box = Nil;/*Tool should detect this line as error*/ /*ERROR: Control flow error*/
void nil_002() {
    Box box1;
    cout << box1.height;
}
"
