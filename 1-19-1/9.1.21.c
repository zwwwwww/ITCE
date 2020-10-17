/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.21
" 1-dimensional array	int	Also known as double Write"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_021 ()
{
	int buf[5];
	int index = 5;
	int index1;
	int index2;
	index1 = index;
	index2 = index1;
	buf[index2] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
