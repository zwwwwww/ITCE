/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.52
omission of the size of the string pointer
*/
                                                                                                  
extern int sink;                                                                                
 void overrun_st_052 ()
{
	char buf[] = "1234";
	buf[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}