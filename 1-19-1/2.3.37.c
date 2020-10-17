/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.37
doing a short read
*/

void dynamic_buffer_underrun_037()
{
	int i;
	char **doubleptr = (char **)malloc(10 * sizeof(char *));

	if (doubleptr != NULL)
	{
		for (i = 0; i < 10; i++)
		{
			doubleptr[i - 10] = (char *)malloc(10 * sizeof(char)); /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
			if (doubleptr[i] != NULL)
			{
				doubleptr[0][0] = 'T';
				free(doubleptr[i]);
			}
		}
		free(doubleptr);
	}
}
