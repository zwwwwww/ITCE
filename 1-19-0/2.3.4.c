/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.4
a pointer to int 2
*/

void dynamic_buffer_underrun_004()
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		*(buf - 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
