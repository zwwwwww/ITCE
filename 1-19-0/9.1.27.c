/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.27
"single float pointer	single Alias Constant 	Write"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_027 ()
{
	float buf[5];
	float *p;
	p = buf;
	*(p + 4) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}