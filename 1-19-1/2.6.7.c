/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.7
"Struct pointer	Write - Global , assigned in another function inside for loop"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_007_s_001;

littlemem_st_007_s_001 *littlemem_st_007_s_001_gbl_str;
#define MAX_STR1 10

char littlemem_st_007_gbl_buf[10];

void littlemem_st_007_func_001()
{
	littlemem_st_007_s_001_gbl_str = (littlemem_st_007_s_001 *)littlemem_st_007_gbl_buf;
}

void littlemem_st_007_func_002(int flag)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (flag == MAX_STR1)
		{
			;
		}
		else
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
		}
	}
}

void littlemem_st_007()
{
	littlemem_st_007_func_001();
	littlemem_st_007_func_002(1);
}
