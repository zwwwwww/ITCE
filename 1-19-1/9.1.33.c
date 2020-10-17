/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.33
"1 pointer int	single Alias Value of random variable	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_033 ()
{
	int buf[5];
	int *p;
	int index;
	p = buf;
	index = rand();
	*(p + index) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
