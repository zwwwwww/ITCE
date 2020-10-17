/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.5
"single pointer	int	Alias for 1 weight	Subtraction	Constant	Write"
*/
                                                                                                     
extern int sink;                                                                                 
void underrun_st_005 ()
{
	int buf[5];
	int *p;
	p = &buf[1];
	*(p - 1) = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
}