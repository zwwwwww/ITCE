/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.22
using 1 single pointer alias
*/
void dynamic_buffer_underrun_022()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int *p;
	if (buf != NULL)
	{
		p = buf;
		*(p - 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
