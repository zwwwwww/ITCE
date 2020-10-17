/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.37
"1 pointer int	single Alias Function arguments	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_037_func_001 (int index)
{
	int buf[5];
	int *p;
	p = buf;
	*(p + index) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}

void overrun_st_037 ()
{
	overrun_st_037_func_001(5);
}
