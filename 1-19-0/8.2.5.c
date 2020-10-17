/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.5
"large internal variables	Large function arguments	Recursive function	10 Level	"
*/


typedef struct
{
#if 0 /* Prevent failure? Correspondence */
	char buf[262144];	/* 256 Kbytes */
#else /* Prevent failure? Correspondence */
	char buf[1024];
#endif
} st_overflow_005_s_001;

void st_overflow_005_func_001(st_overflow_005_s_001 s, int cnt)
{
	if (cnt > 0)
	{
		st_overflow_005_func_001(s, cnt - 1);
	}
	else
	{
		s.buf[0] = 1; /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	}
}

void st_overflow_005()
{
	char buf[4096]; /* 4 Kbytes */
	st_overflow_005_s_001 s;
	st_overflow_005_func_001(s, 10);
	buf[0] = 1;
	sink = buf[idx];
}
"
