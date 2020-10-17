/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.2
"1-dimensional array	int	Constant	Write"
*/
                                                                           
void underrun_st_002 ()
{
	int buf[5];
	buf[-1] = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
}
