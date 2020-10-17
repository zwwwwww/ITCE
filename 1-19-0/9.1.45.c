/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.45
"An array	- An array as function parameter"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_045_func_001 (int buf[])
{
	buf[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}

void overrun_st_045 ()
{
	int buf[5];
	overrun_st_045_func_001(buf);
}