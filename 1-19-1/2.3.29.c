/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.29
in while loop
*/

void dynamic_buffer_underrun_029()
{

	while (1)
	{
		char *buf = (char *)malloc(sizeof(char));
		if (buf != NULL)
		{
			buf[-1] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
			free(buf);
		}
		break;
	}
}
