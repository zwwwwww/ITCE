/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.12
a var access pointers array 1
*/

void dynamic_buffer_overrun_012()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 4;
	if (buf != NULL)
	{
		*(buf + index) = 9; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		free(buf);
	}
}
