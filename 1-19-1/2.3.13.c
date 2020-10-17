/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.13
using a variable to access the pointer array 2
*/


void dynamic_buffer_underrun_013()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 5;
	index = rand() - 2;
	if (buf != NULL)
	{

		buf[-index] = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
