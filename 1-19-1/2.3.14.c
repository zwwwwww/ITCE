/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.14
cast operations 1
*/

void dynamic_buffer_underrun_014()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 3;
	if (buf != NULL)
	{
		*(buf + ((-2 * index) + 1)) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
