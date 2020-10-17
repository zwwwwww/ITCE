/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.15
cast operations 2
*/

void dynamic_buffer_underrun_015()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int index = 2;
	if (buf != NULL)
	{
		buf[(index * index) - 4] = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
