/*
From:ITC
2
Dynamic memory defects
2.4
Memory copy at overlapping areas
2.4.2
substantial memcpy function call
*/

void ow_memcpy_002_func_001(void *dst, const void *src, int size)
{
	unsigned char *p;
	unsigned char *q;
	int i;
	p = (unsigned char *)src;
	q = (unsigned char *)dst;
	for (i = 0; i < size; i++)
	{
		*q = *p; /*Tool should detect this line as error*/ /*ERROR:copy of the overlapped area*/
		p++;
		q++;
	}
}

void ow_memcpy_002()
{
	int buf[5] = {1, 2, 3, 4, 5};
	ow_memcpy_002_func_001(&buf[2], &buf[0], (3 * sizeof(int)));
}
