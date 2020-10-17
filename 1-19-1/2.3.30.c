/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.30
Write outside the allocated buffer in a 2D array
*/

void dynamic_buffer_underrun_030()
{
	int i, j;
	char **doubleptr = (char **)malloc(10 * sizeof(char *));

	for (i = 0; i < 10; i++)
	{
		doubleptr[i] = calloc(10, sizeof(char));
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 9; j >= -1; j--)
		{
			doubleptr[i][j] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		}
		free(doubleptr[i]);
	}
	free(doubleptr);
}
