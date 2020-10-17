/*
From:ITC
14
Object orientedness defects
14.4
Operator equal something
14.4.2
Operator overloading is implemented as a class member function
*/
class person{
private:
    int age;
public:
    person(int a){
        this->age=a;
    }
    inline bool operator == (const person ps) const;//Tools should detect this line as error
};
inline bool person::operator==(const person &ps) const
 {
     if (this->age==ps.age)
         return true;
     return false;
 }
#include<iostream>
using namespace std;
int main()
{
    person p1(10);
    person p2(20);
    if(p1==p2) cout<<"the age is equal!"< return 0;
}
