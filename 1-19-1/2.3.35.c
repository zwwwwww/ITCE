/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.35
using double pointers
*/

void dynamic_buffer_underrun_035()
{
	int i, loc1 = 0, loc2 = 0;
	char **doubleptr = (char **)malloc(10 * sizeof(char *));

	for (i = 0; i < 10; i++)
		doubleptr[i] = (char *)malloc(10 * sizeof(char));

	if (loc1 == 0)
		loc1--;

	doubleptr[loc1][loc2] = 'T';

	if (loc2 == 0)
		loc2--;

	doubleptr[0][loc2] = 'T'; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
	for (i = 0; i < 10; i++)
	{
		free(doubleptr[i]);
	}
	free(doubleptr);
}
