/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.44
increment the pointer value in the loop
*/
                                                                               
 extern int sink;                                                                                       
void overrun_st_044 ()
{
	int buf[5];
	int *p;
	int i;
	p = buf;
	for (i = 0; i <= 5; i ++)
	{
		*p = 1;
		p ++;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
	}
        sink = buf[idx];
}
