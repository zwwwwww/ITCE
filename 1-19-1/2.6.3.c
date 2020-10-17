/*
From:ITC
2
Dynamic memory defects
2.6
Assign small buffer for structure
2.6.3
write pointer union
*/

typedef union
{
	char a;
	short b;
	int c;
} littlemem_st_003_uni_001;

void littlemem_st_003()
{
	char buf[2];
	littlemem_st_003_uni_001 *p;
	p = (littlemem_st_003_uni_001 *)buf;
	p->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}
