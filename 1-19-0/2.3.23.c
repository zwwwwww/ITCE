/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.23
in a for loop
*/

void dynamic_buffer_underrun_023()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int *p;
	int i;
	if (buf != NULL)
	{
		p = buf;
		for (i = 4; i > 0; i--)
		{
			p[i] = '1'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		}
		free(buf);
	}
}
