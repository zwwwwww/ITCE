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
	printf(" underrun2 ");
	short *buf = (short *)calloc(5, sizeof(short));
	if (buf != NULL)
	{
		*(buf - 5) = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(buf);
	}
}
