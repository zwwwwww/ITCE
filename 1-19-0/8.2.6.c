/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.6
"Large function arguments	Function pointer	Level 1	__"
*/


typedef struct
{
#if 0  /* Prevent failure? Correspondence */
	char buf[524288];	 /* 512 Kbytes */
	char buf1[131072];  /* 128 Kbytes */
	char buf2[131072]; /* 128 Kbytes */
	char buf3[1024];
	char buf4[1024];
#else  /* Prevent failure? Correspondence */
	char buf[1024];
#endif /* Prevent failure? Correspondence */
} st_overflow_006_s_001;

void st_overflow_006_func_001(st_overflow_006_s_001 s)
{
	char buf[524288]; /* 512 Kbytes */
	buf[1] = 10;
	s.buf[0] = 1; /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	sink = buf[idx];
}

void st_overflow_006()
{
	st_overflow_006_s_001 s;
	void (*func)(st_overflow_006_s_001);
	func = st_overflow_006_func_001;
	func(s);
}
"
