/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
 2.2.16
a return value from function
*/

int dynamic_buffer_overrun_016_func_001()
{
	return 5;
}

void dynamic_buffer_overrun_016()
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		buf[dynamic_buffer_overrun_016_func_001()] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
