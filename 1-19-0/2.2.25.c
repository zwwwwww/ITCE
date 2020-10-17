/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
 2.2.25
using a char pointer
*/

void dynamic_buffer_overrun_025()
{
	char *buf = (char *)calloc(5, sizeof(char));
	int i;
	if (buf != NULL)
	{
		for (i = 0; i < 5; i++)
		{
			buf[i] = '1'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		}
		free(buf);
	}
}
