/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.39
using memcpy to copy structures
*/

typedef struct
{
	char arr[10];
	int arri[10];
} dynamic_buffer_underrun_s_008;
void dynamic_buffer_underrun_039()
{
	/*dynamic_buffer_underrun_s_008* new_s;*/
	dynamic_buffer_underrun_s_008 *ptr_s1 = malloc(15 * sizeof(dynamic_buffer_underrun_s_008));
	dynamic_buffer_underrun_s_008 ptr_s2[15];
	int i;

	if (ptr_s1 != NULL)
	{
		for (i = 0; i < 15; i++)
		{
			memset(ptr_s1, 1, 15 * sizeof(dynamic_buffer_underrun_s_008)); /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		}
		memcpy(ptr_s2, ptr_s1, 15 * sizeof(dynamic_buffer_underrun_s_008));
		free(ptr_s1);
	}
}
