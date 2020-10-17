/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.5
"single pointer	int	Alias for 1 weight	Subtraction	Constant	Write"
*/
                                                                             
void underrun_st_005 ()
{
	int buf[5];
	int *p;
	p = buf;
	*(p - 1) = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
}
