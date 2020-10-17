/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.25
using a char pointer
*/

void dynamic_buffer_underrun_025()
{
	char *buf = (char *)calloc(5, sizeof(char));
	int i;

	if (buf != NULL)
	{
		for (i = 4; i >= -1; i--)
		{
			buf[i] = '1'; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		}
		free(buf);
	}
}
