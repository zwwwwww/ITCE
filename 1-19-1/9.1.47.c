/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.47
"pointer	- Pointer as function parameter accessed as array"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_047_func_001 (int *p)
{
	p[5] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}

void overrun_st_047 ()
{
	int buf[5];
	overrun_st_047_func_001(buf);
}
