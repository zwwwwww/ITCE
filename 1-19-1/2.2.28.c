/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
      2.2.28
using values in a different array allocated dynamically
*/

void dynamic_buffer_overrun_028()
{
	int *buf1 = (int *)calloc(5, sizeof(int));
	int *buf2 = (int *)calloc(3, sizeof(int));
	int i;
	for (i = 0; i < 5; i++)
	{
		*(buf1 + i) = i;
	}
	*(buf2 + *(buf1 + 5)) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
	free(buf1);
	free(buf2);
}
