/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.5
a pointer to long
*/

void dynamic_buffer_underrun_005()
{
	long *buf = (long *)calloc(5, sizeof(long));
	int i;
	if (buf != NULL)
	{
		for (i = -1; i < 5; i++)
		{
			buf[i] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		}
		free(buf);
	}
}
