/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
 2.2.19
variable
*/

void dynamic_buffer_overrun_019()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 5;
	int index1;
	index1 = index;
	if (buf != NULL)
	{
		buf[index1] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
