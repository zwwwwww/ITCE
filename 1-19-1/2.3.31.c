/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.31
 using memcpy function
*/

void dynamic_buffer_underrun_031()
{
	int i;
	char *ptr1 = (char *)calloc(12, sizeof(char));
	char a[12], *ptr2 = a;
	if (ptr1 != NULL)
	{
		ptr1[11] = '\0';
		for (i = 10; i >= -1; i--) /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		{
			ptr1[i] = 'a';
		}
		memcpy(ptr2, ptr1, 12);
		free(ptr1);
	}
}
