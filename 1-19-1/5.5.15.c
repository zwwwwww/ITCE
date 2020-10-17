/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.15
" a short	int->The return value of the function"
*/
  
extern int sink;         
int data_lost_015_func_001 ()
{
	return 0x8000;
}

void data_lost_015 ()
{
	short ret;
	ret = data_lost_015_func_001();/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}