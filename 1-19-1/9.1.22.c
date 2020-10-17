/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.22
"single char pointer	single Alias Constant Write"
*/
                                                                               
extern int sink;                                                                                       
void overrun_st_022 ()
{
	char buf[5];
	char *p;
	p = buf;
	*(p + 5) = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
