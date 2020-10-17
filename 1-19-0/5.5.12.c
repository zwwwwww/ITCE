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
	a = rand() % 0x8000;
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
