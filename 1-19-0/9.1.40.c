/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.40
"1  pointer	int	Alias for variable double	Write"
*/
                                                                              
extern int sink;                                                                                      
void overrun_st_040 ()
{
	int buf[5];
	int *p;
	int index = 4;
	int index1;
	int index2;
	index1 = index;
	index2 = index1;
	p = buf;
	*(p + index2) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}