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

using namespace std;                                                                                                                            
int use_auto_pointer_004() {
    auto func = []() { std::cout << "Hello world" << std::endl; };/*Tool should detect this line as error*/ /*ERROR:STL error*/
    func();
}
