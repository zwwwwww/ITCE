/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.9
"Struct pointer	Write - Global , assigned in another function inside do - while loop"
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_009_s_001;

littlemem_st_009_s_001 *littlemem_st_009_s_001_gbl_str;
#define MAX_2 10
#define MAX_3 1

char littlemem_st_009_gbl_buf[12];

void littlemem_st_009_func_001()
{
	littlemem_st_009_s_001_gbl_str = (littlemem_st_009_s_001 *)littlemem_st_009_gbl_buf;
}

void littlemem_st_009_func_002(int flag)
{
	int i = 0;
	do
	{
		if (flag == MAX_2)
		{
			;
		}
		else if (flag == MAX_3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should not detect this line as error*/ /*No ERROR:Little Memory or Overflow*/
		}
		i++;
	} while (i < 2);
}

void littlemem_st_009()
{
	littlemem_st_009_func_001();
	littlemem_st_009_func_002(1);
}
