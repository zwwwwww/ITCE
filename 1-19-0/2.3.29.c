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

	/*	int i=0;*/
	while (1)
	{
		char *buf = (char *)malloc(sizeof(char));
		if (buf != NULL)
		{
			buf[0] = 'a'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
			free(buf);
		}
		break;
	}
}
