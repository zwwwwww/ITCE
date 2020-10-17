/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.26
cast  to a larger datatype
*/

void dynamic_buffer_underrun_026()
{
	char *buf = (char *)calloc(5, sizeof(char));
	int *p;
	if (buf != NULL)
	{
		p = (int *)buf;
		*(p - 0) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(buf);
	}
}
