/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.32
using a structure
*/

typedef struct
{
	char arr[10];
	int arri[10];
} dynamic_buffer_overrun_s_005;

void dynamic_buffer_overrun_032()
{
	dynamic_buffer_overrun_s_005 *ptr_s = malloc(10 * sizeof(dynamic_buffer_overrun_s_005));
	int i;
	if (ptr_s != NULL)
	{
		for (i = 0; i <= 10; i++)
		{
			ptr_s[i].arr[i] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/ //vm - Changed arri(int) to arr(char);
		}
		free(ptr_s);
	}
}
