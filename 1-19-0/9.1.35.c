/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.35
" 1  pointer int	single Alias 	Nonlinear equation	Write"
*/
                                                                               
 extern int sink;                                                                                     
  void overrun_st_035 ()
{
	int buf[6];
	int *p;
	int index = 2;
	p = buf;
	*(p + ((index * index) + 1)) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}