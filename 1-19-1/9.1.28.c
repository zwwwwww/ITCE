/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.28
 single double pointer double Alias Constant writ
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_028 ()
{
	double buf[5];
	double *p;
	p = buf;
	*(p + 5) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
