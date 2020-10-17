/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.30
Write outside the allocated buffer in a 2D array
*/

void dynamic_buffer_overrun_030()
{
	int i, j;
	char **doubleptr = (char **)malloc(10 * sizeof(char *));

	for (i = 0; i < 10; i++)
	{
		doubleptr[i] = (char *)malloc(10 * sizeof(char));
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			doubleptr[i][j] = 'a'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		}
		free(doubleptr[i]);
	}
	free(doubleptr);
}
