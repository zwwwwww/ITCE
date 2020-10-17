/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.36
doing a short read using memcpy
*/

void dynamic_buffer_underrun_036()
{
	char test[] = " This is STRING ";
	char *newTest = (char *)malloc(15 * sizeof(char));
	if (newTest != NULL)
	{
		memcpy(newTest, test, 15); /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(newTest);
	}
}
