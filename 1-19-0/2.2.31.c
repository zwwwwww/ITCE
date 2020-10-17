/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.31
using memcpy function
*/

void dynamic_buffer_overrun_031()
{
	int i;
	char *ptr1 = (char *)calloc(12, sizeof(char));
	char a[12], *ptr2 = a;

	if (ptr1 != NULL)
	{
		for (i = 0; i < 11; i++)
		{
			ptr1[i] = 'a'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		}
		ptr1[i] = '\0';
		memcpy(ptr2, ptr1, 11);
		free(ptr1);
	}
}
