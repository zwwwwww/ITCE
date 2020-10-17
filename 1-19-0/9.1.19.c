/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.19
"1-dimensional array	int	An array of element values	Write"
*/
                                                                               
extern int sink;                                                                                      
 void overrun_st_019 ()
{
	int buf[5];
	int indexes[4] = {3, 5, 4, 6};
	int index = 2;
	buf[indexes[index]] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}