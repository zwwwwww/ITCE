/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.29
in while loop
*/


void dynamic_buffer_overrun_029()
{
	int i = 1;
	while (i)
	{
		char *buf = (char *)malloc(sizeof(char));
		if (buf != NULL)
		{
			buf[i + 1] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
			free(buf);
		}
		i--;
	}
}
