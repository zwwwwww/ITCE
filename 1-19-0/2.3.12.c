/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.12
using a variable to access the pointer array 1
*/

void dynamic_buffer_underrun_012()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 0;
	if (buf != NULL)
	{
		*(buf - index) = 9; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
