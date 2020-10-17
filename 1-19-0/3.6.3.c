/*
From:ITC
3
Inappropriate code
3.6
Unused variable
3.6.3
"Union Member	Internal variables"
*/

typedef struct
{
	int a;
	int b;
} unused_var_003_s_001;

typedef struct
{
	int a;
	int b;
} unused_var_003_s_002;

typedef struct
{
	int a;
	int unuse;
} unused_var_003_s_003;

typedef union
{
	unused_var_003_s_001 s1;
	unused_var_003_s_002 s2;
	unused_var_003_s_003 s3;
} unused_var_003_uni_001;

void unused_var_003()
{
	unused_var_003_uni_001 u;

	u.s1.a = 1;
	u.s1.b = 2;
	u.s3.a = u.s2.a + u.s2.b;
	u.s3.unuse = u.s1.a;
	printf(" % d ", u.s3.unuse); /*Tool should not detect this line as error*/ /*No ERROR:Unused variable*/
}
