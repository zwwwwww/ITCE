/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.20
using 2 aliases
*/

void dynamic_buffer_underrun_020()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = -5;
	int index1;
	int index2;
	index1 = index;
	index2 = index1;
	if (buf != NULL)
	{
		buf[index2] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
