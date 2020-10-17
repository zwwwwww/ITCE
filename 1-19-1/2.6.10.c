/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.10
"Struct pointer	Write - Global , assigned in another function inside and goto-00\"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_010_s_001;

littlemem_st_010_s_001 *littlemem_st_010_s_001_gbl_str;

char littlemem_st_010_gbl_buf[10];

void littlemem_st_010_func_001()
{
	littlemem_st_010_s_001_gbl_str = (littlemem_st_010_s_001 *)littlemem_st_010_gbl_buf;
}

void littlemem_st_010_func_002(int flag)
{
	goto label;
label:
	littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

void littlemem_st_010()
{
	littlemem_st_010_func_001();
	littlemem_st_010_func_002(1);
}
