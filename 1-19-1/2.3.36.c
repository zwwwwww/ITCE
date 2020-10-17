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
	char test[] = " This is a test code ";
	char *newTest = (char *)malloc(10 * sizeof(char));
	if (newTest != NULL)
	{
		memcpy(newTest, test, 10);
		char c;
		c = newTest[-10]; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		free(newTest);
	}
}
