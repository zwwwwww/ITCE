/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.34
using string
*/

void dynamic_buffer_underrun_034()
{
	char *srcbuf = " Test Code ";
	int i, loc = 1;
	char *destbuf = (char *)malloc(10 * sizeof(char));
	char ch = 'o';
	if (destbuf != NULL)
	{
		for (i = -1; i < 10; i++)
		{
			if (srcbuf[i] == ch) /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
			{
				loc = i;
			}
		}
		strncpy(&destbuf[loc], &srcbuf[loc], 1);
		free(destbuf);
	}
}
