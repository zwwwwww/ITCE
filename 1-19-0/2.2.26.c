/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.26
cast to larger datatypes
*/

void dynamic_buffer_overrun_026()
{
	char *buf = (char *)calloc(5, sizeof(char));
	int *p;
	p = (int *)buf;
	if (buf != NULL)
	{
		*(p + 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		free(buf);
	}
}
