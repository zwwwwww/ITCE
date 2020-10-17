/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.24
"single int pointer	single Alias Constant 	Loading"
*/
                                                                                  
extern int sink;                                                                                       
void overrun_st_024 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int *p;
	int ret;
	p = buf;
	ret = *(p + 5);/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
