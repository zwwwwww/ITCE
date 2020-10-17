/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.7
a pointer to double
*/

void dynamic_buffer_overrun_007()
{
	double *buf = (double *)calloc(5, sizeof(double));
	int i;
	if (buf != NULL)
	{
		for (i = 0; i <= 5; i++)
		{
			buf[i] = 1.0; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		}
		free(buf);
	}
}
