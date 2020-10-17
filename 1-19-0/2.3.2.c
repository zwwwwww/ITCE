/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.2
a pointer to short
*/

void dynamic_buffer_underrun_002()
{
	short *buf = (short *)calloc(5, sizeof(short));
	if (buf != NULL)
	{
		*(buf - 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
