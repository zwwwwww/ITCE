/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.19
using a variable assigned by some other variable
*/

void dynamic_buffer_underrun_019()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = -5;
	int index1;
	index1 = index;
	if (buf != NULL)
	{
		buf[index1] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
