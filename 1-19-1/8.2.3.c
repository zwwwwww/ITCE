/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.3
"large internal variables	Large function arguments	Function call	Level 1	__"
*/


typedef struct
{
#if 1				   /* Prevent failure? Correspondence */
	char buf[524288];  /* 512 Kbytes */
	char buf1[131072]; /* 128 Kbytes */
	char buf2[131072]; /* 128 Kbytes */
	char buf3[1024];
	char buf4[1024];
#else  /* Prevent failure? Correspondence */
	char buf[1024];
#endif /* Prevent failure? Correspondence */
} st_overflow_003_s_001;

void st_overflow_003_func_001(st_overflow_003_s_001 s)
{
	char buf[524288]; /* 512 Kbytes */ /*Tool should detect this line as error*/ /*ERROR:Stack overflow*/
	s.buf[0] = 1;
	buf[0] = 1;
	sink = buf[idx];
}

void st_overflow_003()
{
	st_overflow_003_s_001 s;	 /* 5 Kbytes */
	st_overflow_003_func_001(s); /* 5 Kbytes */
}
"
