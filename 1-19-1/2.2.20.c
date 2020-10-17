/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.20
2 aliases
*/

void dynamic_buffer_overrun_020()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 5;
	int index1;
	int index2;
	index1 = index;
	index2 = index1;
	if (buf != NULL)
	{
		buf[index2] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
