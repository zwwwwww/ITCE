/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.5
a pointer to long
*/

void dynamic_buffer_overrun_005()
{
	long *buf = (long *)calloc(5, sizeof(long));
	int i;
	if (buf != NULL)
	{
		for (i = 0; i <= 5; i++)
		{
			buf[i] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		}
		free(buf);
	}
}
