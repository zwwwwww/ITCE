/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.32
"1 pointer	int	single Alias 	Variable	Write"
*/
                                                                              
extern int sink;                                                                                       
void overrun_st_032 ()
{
	int buf[5];
	int *p;
	int index = 5;
	p = buf;
	*(p + index) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
