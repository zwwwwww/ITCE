/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.12
using switch case
*/
 
typedef struct {
	int a;
	int b;
	int uninit;
} invalid_memory_access_012_s_001;

int invalid_memory_access_012_func_001 (int flag)
{

	invalid_memory_access_012_s_001 *s;
	s = (invalid_memory_access_012_s_001 *)calloc(1,sizeof(invalid_memory_access_012_s_001));
	int i=0;
	switch (flag)
	{
		case 1:
		{
			if(s!=NULL)
			{
			     s->a = 10;
			     s->b = 10;
			     s->uninit = 10; /*Tool should not detect this line as error*/ /*No ERROR:Invalid memory access to already freed area*/
			     i=s->a;
     			 free(s);
			}
			break;
		}
		case 2:
		{
			if(s!=NULL)
			{
			     s->a = 20;
			     s->b = 20;
			     s->uninit = 20;
			     i=s->a;
     			 free(s);
			}
			break;
		}
		default:
		{
			free(s);
			break;
		}
	}
	/*return s->a;*/
	return i;
}

void invalid_memory_access_012 ()
{
	int ret;
	ret = invalid_memory_access_012_func_001 (1);
	printf("%d",ret);
}
