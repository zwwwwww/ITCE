/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.28

*/

void dynamic_buffer_underrun_028()
{
	int *buf1 = (int *)calloc(5, sizeof(int));
	int *buf2 = (int *)calloc(3, sizeof(int));
	int i;

	for (i = 0; i < 5; i++)
	{
		*(buf1 + i) = i;
	}
	*(buf2 - *(buf1 + 4)) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
	free(buf1);
	free(buf2);
}
