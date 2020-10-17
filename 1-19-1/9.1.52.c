/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.52
omission of the size of the string pointer
*/
                                                                           
 void overrun_st_052 ()
{
	char buf[] = "1234";
	buf[5] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}
