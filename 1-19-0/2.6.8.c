/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.8
"Struct pointer	Write - Global , assigned in another function inside while loop"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_008_s_001;

littlemem_st_008_s_001 *littlemem_st_008_s_001_gbl_str;
#define MAX_STR2 10
#define MAX_STR3 1

char littlemem_st_008_gbl_buf[12];

void littlemem_st_008_func_001()
{
	littlemem_st_008_s_001_gbl_str = (littlemem_st_008_s_001 *)littlemem_st_008_gbl_buf;
}

void littlemem_st_008_func_002(int flag)
{
	int i = 0;
	while (i < 2)
	{
		if (flag == MAX_STR2)
		{
			;
		}
		else if (flag == MAX_STR3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should not detect this line as error*/ /*No ERROR:Little Memory or Overflow*/
		}
		i++;
	}
}

void littlemem_st_008()
{
	littlemem_st_008_func_001();
	littlemem_st_008_func_002(1);
}
