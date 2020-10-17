/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.17
" 1-dimensional array	int	The return value of the function	Write"
*/
                                                                               
 extern int sink;                                                                                      
 int overrun_st_017_func_001 ()
{
	return 5;
}

void overrun_st_017 ()
{
	int buf[5];
	buf[overrun_st_017_func_001()] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
