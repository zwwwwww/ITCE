/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
 2.2.4
a pointer to int 2
*/

void dynamic_buffer_overrun_004()
{
	int *buf = (int *)calloc(5, sizeof(int));
	if (buf != NULL)
	{
		*(buf + 4) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		free(buf);
	}
}
