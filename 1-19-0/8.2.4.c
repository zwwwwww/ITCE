/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.4
"large internal variables	Large function arguments	Function call	2 Level	__"
*/


typedef struct
{
#if 0  /* Prevent failure? Correspondence */
	char buf[524288];	/* 512 Kbytes */
	char buf1[131072];/* 128 Kbytes */
	char buf2[1024];
	char buf3[1024];
#else  /* Prevent failure? Correspondence */
	char buf[1024];
	char buf1[1024];
	char buf2[1024];
#endif /* Prevent failure? Correspondence */
} st_overflow_004_s_001;

void st_overflow_004_func_002(st_overflow_004_s_001 s)
{
	char buf[131072]; /* 128 Kbytes */
	s.buf[0] = 1;
	buf[0] = 1;
	sink = buf[idx];
}

void st_overflow_004_func_001(st_overflow_004_s_001 s)
{
	char buf[131072]; /* 128 Kbytes */ /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	buf[0] = 1;
	st_overflow_004_func_002(s);
	sink = buf[idx];
}

void st_overflow_004()
{
	st_overflow_004_s_001 s;
	st_overflow_004_func_001(s);
}
"
