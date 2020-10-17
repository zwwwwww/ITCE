/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.13
"1-dimensional array	int	Variable	Write"
*/
                                                                              
extern int sink;                                                                                       
void overrun_st_013 ()
{
	int buf[5];
	int index = 5;
	buf[index] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
