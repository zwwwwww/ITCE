/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.6
"single pointer	int	Alias for 1 weight	Subtraction	Variable	Write"
*/
                                                                             
void underrun_st_006 ()
{
	int buf[5];
	int *p;
	int index = 1;
	p = buf;
	*(p - index) = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
}
