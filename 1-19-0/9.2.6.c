/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.6
"single pointer	int	Alias for 1 weight	Subtraction	Variable	Write"
*/
                                                                                                    
extern int sink;                                                                                
void underrun_st_006 ()
{
	int buf[5];
	int *p;
	int index = 1;
	p = &buf[1];
	*(p - index) = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
}