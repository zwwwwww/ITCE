/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.13
a var access pointers array 2
*/

void dynamic_buffer_overrun_013()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 4;
	if (buf != NULL)
	{
		buf[index] = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		free(buf);
	}
}
