/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.12
"a short	int->Value of random variable"
*/
  
extern int sink;      
int rand(void);      
void data_lost_012 ()
{
	short ret;
	int a;
	a = rand();
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}