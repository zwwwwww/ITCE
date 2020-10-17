/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.15
index variable 2
*/

void dynamic_buffer_overrun_015()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 2;
	if (buf != NULL)
	{
		buf[(index * index) + 1] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
