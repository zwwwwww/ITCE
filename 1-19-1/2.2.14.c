/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.14
index variable 1
*/

void dynamic_buffer_overrun_014()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 3;
	if (buf != NULL)
	{
		*(buf + ((2 * index) + 1)) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
