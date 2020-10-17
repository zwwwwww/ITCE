/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.15
"1-dimensional array	int	Linear equation	Write"
*/
                                                                                
extern int sink;                                                                                      
 void overrun_st_015 ()
{
	int buf[6];
	int index = 2;
	buf[(2 * index) + 1] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}