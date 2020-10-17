/*
From:ITC
14
Object orientedness defects
14.3
No constructor
14.3.1
no constructor
*/
#include <iostream>
#include<sstream>
using namespace std;

class Complex {
    double re;
    double im;
public:
    string text() {
        stringstream s;
        s << re << " + " << im << "j";
        return s.str();
    }
};
int no_constructor_001() {
    Complex a = { 1.0, 2.0 }; /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
    cout << "a = " << a.text();
    Complex b = { 4.0, 5.0 }; //再次调用构造函数Complex
    cout << "b = " << b.text();
}
