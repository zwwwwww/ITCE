/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.2
writing structure pointer
*/

typedef struct
{
	int a;
	int b;
	int c;
} littlemem_st_002_s_001;

void littlemem_st_002()
{
	char buf[12];
	littlemem_st_002_s_001 *p;
	p = (littlemem_st_002_s_001 *)buf;
	p->c = 1; /*Tool should not detect this line as error*/ /*No ERROR:Little Memory or Overflow*/
}
