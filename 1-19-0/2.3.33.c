/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.33

*/

void dynamic_buffer_underrun_033()
{
	char *message = (char *)calloc(12, sizeof(char));
	int index = 12;
	int len = index - 1;
	int c;
	if (message != NULL)
	{
		while (len > 0)
		{
			c = message[len];
			if (isspace(c))
			{
				message[len] = '\n'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
			}

			len--;
		}
		free(message);
	}
}
