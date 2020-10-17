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
#include<iostream>
using namespace std;                                                                                                                                                        
class Shape;

std::shared_ptr<Shape> globalShape;

void g(Shape& s) {
    globalShape.reset();
    // do something with parameter s
}

void use_auto_pointer_005() {
    auto myShape = globalShape; // reference count of the smart pointer is incremented, the pointer-to object is kept alive
    g(*myShape);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
