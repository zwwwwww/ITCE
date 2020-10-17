/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.29
" double pointer	int	single Alias for Constant Write"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_029 ()
{
	int buf[5];
	int *p;
	int **pp;
	p = buf;
	pp = &p;
	*(*pp + 4) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}