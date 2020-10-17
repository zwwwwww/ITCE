/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
      2.2.24
passing the base pointer to a function
*/

void dynamic_buffer_overrun_024_func_001(int *buf)
{
	*(buf + 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
}

void dynamic_buffer_overrun_024()
{
	int *buf = (int *)calloc(5, sizeof(int));

	dynamic_buffer_overrun_024_func_001(buf);
	if (buf != NULL)
	{
		free(buf);
	}
}
