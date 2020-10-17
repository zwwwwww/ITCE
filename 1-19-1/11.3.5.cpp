/*
From:ITC
11
STL defects
11.3
"use auto pointer
"
11.3.5
 pointers or references obtained from aliased smart pointers be used as function parameters
*/

using namespace std;                                                                                                                                                                          
class Shape;

std::shared_ptr<Shape> globalShape;

void g(Shape& s) {
    globalShape.reset();
    // do something with parameter s
}
void use_auto_pointer_005() { /*Tool should detect this line as error*/ /*ERROR:STL error*/
    g(*globalShape); // Noncompliant, lifecycle of the reference is not controlled, parameter s of function g will be a dangling reference
}

