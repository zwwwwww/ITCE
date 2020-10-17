/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.27
cast to a smaller datatype
*/

void dynamic_buffer_underrun_027()
{
	int *buf = (int *)calloc(5, sizeof(int));
	char *p;
	if (buf != NULL)
	{
		p = (char *)buf;
		*(p - 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
