/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.53
cast large data size-small size
*/
                                                                               
extern int sink;                                                                                       
void overrun_st_053 ()
{
	char buf[8];
	int *p;
	p = (int*)buf;
	*(p + 1) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}