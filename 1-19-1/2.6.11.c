/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.11
"Struct pointer	Write - Global , assigned in another function inside while loop and goto"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_011_s_001;

littlemem_st_011_s_001 *littlemem_st_011_s_001_gbl_str;

char littlemem_st_011_gbl_buf[10];

void littlemem_st_011_func_001()
{
	littlemem_st_011_s_001_gbl_str = (littlemem_st_011_s_001 *)littlemem_st_011_gbl_buf;
}

void littlemem_st_011_func_002(int flag)
{
	int i = 0;
	goto label;

label:
	while (i < 2)
	{
		littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
		i++;
	}
}

void littlemem_st_011()
{
	littlemem_st_011_func_001();
	littlemem_st_011_func_002(1);
}
