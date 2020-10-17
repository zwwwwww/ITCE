/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.17
overrun in the function called
*/
void dynamic_buffer_overrun_017_func_001(int index)
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		*(buf + index) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}

void dynamic_buffer_overrun_017()
{
	dynamic_buffer_overrun_017_func_001(5);
}
