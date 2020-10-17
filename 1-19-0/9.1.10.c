/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.10
"pointer arrays	int	Constant	Write"
*/
                                                                               
extern int sink;                                                                                       
void overrun_st_010 ()
{
	int buf1[5];
	int buf2[5];
	int buf3[5];
	int buf4[5];
	int buf5[6];
	int *pbuf[5] = {buf1, buf2, buf3, buf4, buf5};
	pbuf[4][5] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}