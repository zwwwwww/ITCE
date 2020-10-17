/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.6
"Struct pointer	Write - Global , assigned in another function inside if condition"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_006_s_001;

littlemem_st_006_s_001 *littlemem_st_006_s_001_gbl_str;
#define MAX_STR 10

char littlemem_st_006_gbl_buf[12];

void littlemem_st_006_func_001()
{
	littlemem_st_006_s_001_gbl_str = (littlemem_st_006_s_001 *)littlemem_st_006_gbl_buf;
}

void littlemem_st_006_func_002(int flag)
{
	if (flag == MAX_STR)
	{
		littlemem_st_006_s_001_gbl_str->c = 1; /*Tool should not detect this line as error*/ /*No ERROR:Little Memory or Overflow*/
	}
}

void littlemem_st_006()
{
	littlemem_st_006_func_001();
	littlemem_st_006_func_002(10);
}
