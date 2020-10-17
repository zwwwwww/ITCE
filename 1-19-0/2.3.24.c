/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.24
passing the base pointer to a function
*/

void dynamic_buffer_underrun_024_func_001(int *buf)
{
	*(buf - 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
}

void dynamic_buffer_underrun_024()
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		dynamic_buffer_underrun_024_func_001(buf);
		free(buf);
	}
}
