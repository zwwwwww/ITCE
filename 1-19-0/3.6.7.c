/*
From:ITC
3
Inappropriate code
3.6
Unused variable
3.6.7
"Union Member	Internal variables"
*/

typedef struct
{
	int a;
	int b;
} unused_var_007_s_001;

typedef struct
{
	int a;
	int b;
} unused_var_007_s_002;

typedef struct
{
	int a;
	int unuse;
} unused_var_007_s_003;

typedef union
{
	unused_var_007_s_001 s1;
	unused_var_007_s_002 s2;
	unused_var_007_s_003 s3;
} unused_var_007_uni_001;

unused_var_007_uni_001 unused_var_007_uni_001_gbl;
void unused_var_007()
{
	unused_var_007_uni_001_gbl.s1.a = 1;
	unused_var_007_uni_001_gbl.s1.b = 2;
	unused_var_007_uni_001_gbl.s3.a = unused_var_007_uni_001_gbl.s1.a + unused_var_007_uni_001_gbl.s1.b; /*Tool should detect this line as error*/ /*ERROR:Unused variable*/
	printf(" % d ", unused_var_007_uni_001_gbl.s3.a); /*Tool should not detect this line as error*/												   /*No ERROR:Unused variable*/
}
