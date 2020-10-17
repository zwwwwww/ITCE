/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.18
array as the index
*/

void dynamic_buffer_underrun_018()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int indexes[4] = {3, 4, 5, 6};
	int index = 2;
	if (buf != NULL)
	{
		*(buf - indexes[index]) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
