/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.27
cast to smaller datatypes
*/

void dynamic_buffer_overrun_027()
{
	int *buf = (int *)calloc(5, sizeof(int));
	char *p;
	p = (char *)buf;
	if (buf != NULL)
	{
		*(p + 30) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
