/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.14
tructure passed as function parameter and based on the return value of function another structure is initialized
*/

typedef struct {
	int a;
	int b;
	int uninit;
} uninit_pointer_014_s_001;

uninit_pointer_014_s_001 *s;
void uninit_pointer_014_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			s = (uninit_pointer_014_s_001 *)calloc(1,sizeof(uninit_pointer_014_s_001));
			if(s!=NULL)
			{
				s->a = 10;
			    s->b = 10;
			}
			break;
		}
		case 2:
		{
			s = (uninit_pointer_014_s_001 *)calloc(1,sizeof(uninit_pointer_014_s_001));
			if(s!=NULL)
			{
				s->a = 20;
			    s->b = 20;
			}
			break;
		}
		default:
		{
			break;
		}

	}
}

void uninit_pointer_014 ()
{
	uninit_pointer_014_s_001 r;
	uninit_pointer_014_func_001 (1);
	if(s!=NULL)
	{
	    r = *s;/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
	    free(s);
	}
}