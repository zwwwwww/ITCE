/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
      2.2.22
1 single pointer alias
*/

void dynamic_buffer_overrun_022()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int *p;
	if (buf != NULL)
	{
		p = buf;
		*(p + 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
