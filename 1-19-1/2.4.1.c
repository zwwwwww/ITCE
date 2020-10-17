/*
From:ITC
2
Dynamic memory defects
2.4
Memory copy at overlapping areas
2.4.1
loop in a function
*/

void ow_memcpy_001()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < 3; i++)
	{
		buf[i] = buf[i + 2]; /*Tool should detect this line as error*/ /*ERROR:copy of the overlapped area*/
	}
}
