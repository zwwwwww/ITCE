/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.7
"large internal variables	Large function arguments	Function call	Level 1	Split condition is"
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
} st_overflow_007_s_001;

void st_overflow_007_func_002(st_overflow_007_s_001 s);
void st_overflow_007_func_001(st_overflow_007_s_001 s)
{
	char buf[262144]; /* 256 Kbytes */
	s.buf[0] = 1;
	buf[0] = 1;
	st_overflow_007_func_002(s);
	sink = buf[idx];
}

void st_overflow_007_func_002(st_overflow_007_s_001 s)
{
	char buf[262144]; /* 256 Kbytes */
	buf[0] = 1;
	s.buf[0] = 1; /*Tool should detect this line as error*/ /*ERROR:Stack overflow*/
	sink = buf[idx];
}

void st_overflow_007()
{
	st_overflow_007_s_001 s; /* 6 Kbytes */
	int flag = 10;
	if (flag)
	{
		st_overflow_007_func_001(s); /* 6 Kbytes */
	}
	else
	{
		st_overflow_007_func_002(s); /* 6 Kbytes */
	}
}
"
