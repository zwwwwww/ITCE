/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.2
a pointer to short
*/

void dynamic_buffer_overrun_002()
{
	short *buf = (short *)calloc(5, sizeof(short));
	if (buf != NULL)
	{
		*(buf + 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}
