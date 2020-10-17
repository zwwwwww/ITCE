/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.17
underrun in the function called
*/

void dynamic_buffer_underrun_017_func_001(int index)
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		*(buf - index) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}

void dynamic_buffer_underrun_017()
{
	dynamic_buffer_underrun_017_func_001(5);
}
