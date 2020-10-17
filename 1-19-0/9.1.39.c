/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.39
" 1  pointer	int	Alias for variable 	Write"
*/
                                                                               
 extern int sink;                                                                                       
void overrun_st_039 ()
{
	int buf[5];
	int *p;
	int index = 4;
	int index1;
	index1 = index;
	p = buf;
	*(p + index1) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}