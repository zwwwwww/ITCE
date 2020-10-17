/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.13
"Double pointer - double	Alias for 1 weight	Address	Constant	Write"
*/
    
typedef struct {
	int a;
	int b;
	int uninit;
} invalid_memory_access_013_s_001;
invalid_memory_access_013_s_001 *invalid_memory_access_013_s_001_s_gbl;

void invalid_memory_access_013_func_001 (int flag)
{
	if(flag >0)
	invalid_memory_access_013_s_001_s_gbl = (invalid_memory_access_013_s_001 *)calloc(1,sizeof(invalid_memory_access_013_s_001));
}

int invalid_memory_access_013_func_002 (int flag)
{
	int i=0;
	switch (flag)
	{
		case 1:
		{
			if (invalid_memory_access_013_s_001_s_gbl != NULL)
			{
				invalid_memory_access_013_s_001_s_gbl->a = 10;
				invalid_memory_access_013_s_001_s_gbl->b = 10;
				invalid_memory_access_013_s_001_s_gbl->uninit = 10;
				i=invalid_memory_access_013_s_001_s_gbl->a;
				free(invalid_memory_access_013_s_001_s_gbl);
			}
			break;
		}
		case 2:
		{
			if (invalid_memory_access_013_s_001_s_gbl != NULL)
			{
				invalid_memory_access_013_s_001_s_gbl->a = 20;
				invalid_memory_access_013_s_001_s_gbl->b = 20;
				invalid_memory_access_013_s_001_s_gbl->uninit = 20;
				i=invalid_memory_access_013_s_001_s_gbl->a;
				free(invalid_memory_access_013_s_001_s_gbl);
			}
			break;
		}
		default:
		{
			break;
		}
	}
	return invalid_memory_access_013_s_001_s_gbl->a;/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
/*	return i;*/
}

void invalid_memory_access_013_func_003 (int flag)
{
	invalid_memory_access_013_s_001 s;
	if(flag >0)
	{
		if (invalid_memory_access_013_s_001_s_gbl != NULL)
		{
			s.a = invalid_memory_access_013_s_001_s_gbl->a;
			s.b = invalid_memory_access_013_s_001_s_gbl->b;
			s.uninit = invalid_memory_access_013_s_001_s_gbl->uninit;
		}
	}
}

void invalid_memory_access_013 ()
{
	int ret;
	invalid_memory_access_013_func_001 (1);
	ret = invalid_memory_access_013_func_002 (1);
	invalid_memory_access_013_func_003 (0);

	printf("%d",ret);
}