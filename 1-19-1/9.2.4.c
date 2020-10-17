/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.4
"single pointer	int	Alias for 1 weight	Subtraction	Constant	Loading"
*/
                                                                          
void underrun_st_004 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int *p;
	int ret;
	p = buf;
	ret = *(p - 1);/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
}
