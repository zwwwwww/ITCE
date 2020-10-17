/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.51
omission of the pointer array array size
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_051 ()
{
	int buf1[] = {1, 2, 3, 4, 5, 6};
	int buf2[] = {1, 2, 3, 4, 5, 6};
	int buf3[] = {1, 2, 3, 4, 5, 6};
	int buf4[] = {1, 2, 3, 4, 5, 6};
	int buf5[] = {1, 2, 3, 4, 5};
	int *pbuf[] = {buf1, buf2, buf3, buf4, buf5};
	pbuf[4][5] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}
