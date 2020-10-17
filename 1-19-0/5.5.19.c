/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.19
"a short->	int- double alias"
*/
   
extern int sink;         
void data_lost_019 ()
{
	short ret;
	int a = 0x7fff;
	int a1;
	int a2;
	a1 = a;
	a2 = a1;
	ret = a2;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
