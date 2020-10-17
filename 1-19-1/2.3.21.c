/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.21
using 2 pointer aliases
*/

void dynamic_buffer_underrun_021()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int *p1;
	int *p2;
	if (buf != NULL)
	{
		p1 = buf;
		p2 = p1;
		*(p2 - 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
