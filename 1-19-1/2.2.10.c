/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
2.2.10
pointers to struct
*/

typedef struct
{
	int a;
	int b;
	int c;
} dynamic_buffer_overrun_010_s_001;

void dynamic_buffer_overrun_010()
{
	dynamic_buffer_overrun_010_s_001 *sbuf = calloc(5, sizeof(dynamic_buffer_overrun_010_s_001));
	if (sbuf != NULL)
	{
		sbuf[5].a = 1; /*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(sbuf);
	}
}
