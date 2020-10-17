/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.38
" 1  pointer	int	Alias An array of element values	Write"
*/
                                                                                
 extern int sink;                                                                                       
void overrun_st_038 ()
{
	int buf[5];
	int *p;
	int indexes[4] = {3, 5, 4, 6};
	int index = 2;
	p = buf;
	*(p + indexes[index]) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}