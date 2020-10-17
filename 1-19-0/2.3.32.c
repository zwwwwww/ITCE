/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.32
using a structure
*/

typedef struct
{
	char arr[10];
	int arri[10];
} dynamic_buffer_underrun_s_032;

void dynamic_buffer_underrun_032()
{
	dynamic_buffer_underrun_s_032 *ptr_s = calloc(10, sizeof(dynamic_buffer_underrun_s_032));
	int i;

	if (ptr_s != NULL)
	{
		for (i = 0; i < 10; i++)
			ptr_s[i].arr[i] = 'a'; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(ptr_s);
	}
}
