/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.38
using structures
*/

typedef struct
{
	char arr[10];
	int arri[10];
} dynamic_buffer_underrun_s_038;
void dynamic_buffer_underrun_038()
{
	dynamic_buffer_underrun_s_038 *new_s = malloc(10 * sizeof(dynamic_buffer_underrun_s_038));
	/*	dynamic_buffer_underrun_s_007* ptr_s=malloc(10*sizeof(dynamic_buffer_underrun_s_007));*/
	int loc = -1, i = 0;

	if (new_s != NULL)
	{
		new_s[loc].arr[i] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Buffer Underrun*/
		new_s[0].arri[i] = 2;
		free(new_s);
	}
}
