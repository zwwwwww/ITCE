/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.2
 Level 1 - large function argument function call 
*/


typedef struct
{
#if 1				  /* Prevent failure? Correspondence */
	char buf[524288]; /* 1 Mbytes */
	char buf1[65536];
	char buf2[65536];
	char buf3[65536];
	char buf4[65536];
	char buf5[65536];
	char buf6[65536];
	char buf7[65536];
	char buf8[65536];
#else
	char buf[1024];
#endif /* Prevent failure? Correspondence */
} st_overflow_002_s_001;

void st_overflow_002_func_001(st_overflow_002_s_001 s)
{
	s.buf[0] = 1; /*Tool should detect this line as error*/ /*ERROR:Stack overflow*/
}

void st_overflow_002()
{
	st_overflow_002_s_001 s;	 /* 1 Mbytes */
	st_overflow_002_func_001(s); /* 1 Mbytes */
}
"
