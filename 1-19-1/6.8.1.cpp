/*
From:ITC
6
Pointer related defects
6.8
unaligned pointer
6.8.1
pointer is unaligned
*/

using namespace std;
void FuncA(double& x)
{
    x = 0;
}
void FuncB(double* x)
{
    *x = 0;
}
struct MyStruct
{
    char c;
    double x;
};

void unaligned_001()
{
    MyStruct M;
    FuncA(M.x);  // This is OK
    FuncB(&M.x); // This generates a warning C4366  /*Tool should detect this line as error*/ /*ERROR:Pointer related error*/
}
