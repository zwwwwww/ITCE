/*
From:ITC
2
Dynamic memory defects
2.3
Dynamic buffer underrrun
2.3.11
pointers to structure with an array
*/

typedef struct
{
	int a;
	int b;
	int buf[5];
} dynamic_buffer_underrun_011_s_001;

void dynamic_buffer_underrun_011()
{
	dynamic_buffer_underrun_011_s_001 *s = (dynamic_buffer_underrun_011_s_001 *)calloc(5, sizeof(dynamic_buffer_underrun_011_s_001));
	if (s != NULL)
	{
		(s + 0)->buf[4] = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer Underrun*/
		free(s);
	}
}
