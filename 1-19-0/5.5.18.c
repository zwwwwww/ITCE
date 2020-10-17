/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.18
"a short	int->Alias for 1 weight"
*/
      
extern int sink;            
void data_lost_018 ()
{
	short ret;
	int a = 0x7fff;
	int a1;
	a1 = a;
	ret = a1;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}