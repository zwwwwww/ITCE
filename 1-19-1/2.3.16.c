/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.16
return value to access memory
*/

int dynamic_buffer_underrun_016_func_001()
{
	return -1;
}

void dynamic_buffer_underrun_016()
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		buf[dynamic_buffer_underrun_016_func_001()] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
