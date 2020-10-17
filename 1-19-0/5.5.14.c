/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.14
" a short	int->Nonlinear equation"
*/
                           
extern int sink;                                 
void data_lost_014 ()
{
	short ret;
	int a = 181;
	ret = (a * a) + 6;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
