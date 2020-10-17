/*
From:ITC
14
Object orientedness defects
14.4
Operator equal something
14.4.1
Operator overload implemented as a non class member function (global function)
*/
class person
{
public:
    int age;
public:
};
bool operator==(person const &p1 ,person const  p2)
{//Tools should detect this line as error
    if(p1.age==p2.age)
        return true;
    return false;
}
int operator_001()
{
    person rose;
    person jack;
    rose.age=18;
    jack.age=23;
    if(rose==jack)
        cout<<"ok"< return 0;
}
