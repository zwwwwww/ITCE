/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.18
"1-dimensional array	int	Function arguments	Write"
*/
int overrun_st_018_buf[5];
void overrun_st_018_func_001 (int index)
{
	overrun_st_018_buf[index] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}

void overrun_st_018 ()
{
	overrun_st_018_func_001(5);
}
