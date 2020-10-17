/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.8
double pointers to int 1
*/

void dynamic_buffer_overrun_008()
{
	int **buf = (int **)calloc(5, sizeof(int *));
	int i, j;

	for (i = 0; i < 5; i++)
		buf[i] = (int *)calloc(5, sizeof(int));

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			*(*(buf + i) + j) = i; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		}
		free(buf[i]);
	}
	free(buf);
}
