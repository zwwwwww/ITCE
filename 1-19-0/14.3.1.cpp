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
    Complex(const double r, const double i) { //�������Ĺ��캯��
        cout << "���ù��캯��:\n";
        re = r;
        im = i;
    }
    string text() {
        stringstream s;
        s << re << " + " << im << "j";
        return s.str();
    }
};
int no_constructor_001() {
    Complex a = { 1.0, 2.0 }; /*Tool should Not detect this line as error*/ /*ERROR:Object orientedness error*/
    cout <<"a = " << a.text();
    Complex b = { 4.0, 5.0 }; //�ٴε��ù��캯��Complex
    cout << "b = " << b.text();
}
