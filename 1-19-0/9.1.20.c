/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.20
"1-dimensional array	int	Alias for 1 weight	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_020 ()
{
	int buf[5];
	int index = 4;
	int index1;
	index1 = index;
	buf[index1] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}