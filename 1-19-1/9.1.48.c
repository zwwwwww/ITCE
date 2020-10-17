/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.48
pointer - An array as function parameter
*/
                                                                                
 extern int sink;                                                                                       
void overrun_st_048_func_001 (int buf[])
{
	*(buf + 5) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}

void overrun_st_048 ()
{
	int buf[5];
	overrun_st_048_func_001(buf);
        sink = buf[idx];
}
