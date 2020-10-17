/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.6
"1-dimensional array	float	Constant	Write"
*/
                                                                               
 extern int sink;                                                                                       
void overrun_st_006 ()
{
	float buf[5];
	buf[5] = 1.0;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
