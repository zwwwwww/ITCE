/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.36
"1  pointer	int	single Alias 	The return value of the function	Write"
*/
                                                                                
extern int sink;                                                                                       
int overrun_st_036_func_001 ()
{
	return 5;
}

void overrun_st_036 ()
{
	int buf[5];
	int *p;
	p = buf;
	*(p + overrun_st_036_func_001()) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
