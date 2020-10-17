/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
        2.2.3
a pointer to int 1
*/

void dynamic_buffer_overrun_003()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int ret;
	int i;
	if (buf != NULL)
	{
		for (i = 0; i < 5; i++)
		{
			buf[i] = 1;
		}
		ret = buf[5]; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
		printf(" % d ", ret);
	}
}
