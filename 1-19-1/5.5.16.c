/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.16
"a short	int->Function arguments  "
*/
  
extern int sink;      
void data_lost_016_func_001 (int a)
{
	short ret;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

void data_lost_016 ()
{
	data_lost_016_func_001(0x8000);
}