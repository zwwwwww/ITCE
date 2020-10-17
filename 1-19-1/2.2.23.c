/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
      2.2.23
in a for loop
*/

void dynamic_buffer_overrun_023()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int *p;
	int i;
	if (buf != NULL)
	{
		p = buf;
		for (i = 0; i <= 5; i++)
		{
			*p = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
			p++;
		}
		free(buf);
	}
}
