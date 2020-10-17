/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.6
a pointer to float
*/


void dynamic_buffer_underrun_006()
{
	float *buf = (float *)calloc(5, sizeof(float));
	int i;
	if (buf != NULL)
	{
		for (i = -1; i < 5; i++)
		{
			buf[i] = 1.0; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		}
		free(buf);
	}
}
