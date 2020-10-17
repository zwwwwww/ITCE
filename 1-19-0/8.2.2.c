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
#if 0 /* Prevent failure? Correspondence */
	char buf[524288];	/* 512Kbytes */
	char buf1[65536];	/* 64 Kbytes */
	char buf2[65536];	/* 64 Kbytes */
	char buf3[65536];	/* 64 Kbytes */
	char buf4[65536];	/* 64 Kbytes */
	char buf5[65536];	/* 64 Kbytes */
	char buf6[65536];	/* 64 Kbytes */
	char buf7[65536];	/* 64 Kbytes */
	char buf8[65536];	/* 64 Kbytes */
#else
	char buf[1024];
#endif /* Prevent failure? Correspondence */
} st_overflow_002_s_001;

void st_overflow_002_func_001(st_overflow_002_s_001 s)
{
	s.buf[0] = 1;
}

void st_overflow_002()
{
	st_overflow_002_s_001 s;	 /* 1 Kbytes */
	st_overflow_002_func_001(s); /* 1 Kbytes */
}
"
