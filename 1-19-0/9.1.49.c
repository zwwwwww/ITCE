/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.49
 abbreviation for 1-dimensional array array size
*/
                                                                                
 extern int sink;                                                                                       
void overrun_st_049 ()
{
	int buf[] = {1, 2, 3, 4, 5};
	buf[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}