/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.34
"1  pointer	int	single Alias Linear equation	Write"
*/
                                                                                 
 extern int sink;                                                                                       
void overrun_st_034 ()
{
	int buf[5];
	int *p;
	int index = 2;
	p = buf;
	*(p + ((2 * index) + 1)) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
