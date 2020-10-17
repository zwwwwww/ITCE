/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.3
"1-dimensional array	int	Constant	Loading"
*/
                                                                                  
extern int sink;                                                                                      
 void overrun_st_003 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int ret;
	ret = buf[4]; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = ret + buf[idx];
}
