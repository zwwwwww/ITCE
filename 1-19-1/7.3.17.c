/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.17
"global char pointer  variable initialized in another function , freed in another function based in while loop"
*/
       
char *invalid_memory_access_017_doubleptr_gbl;         
int invalid_memory_access_017_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void invalid_memory_access_017_func_002()
{
	invalid_memory_access_017_doubleptr_gbl=(char*) malloc(10*sizeof(char));
	if(invalid_memory_access_017_doubleptr_gbl !=NULL)
	strcpy(invalid_memory_access_017_doubleptr_gbl,"TEST");
}

void invalid_memory_access_017_func_003()
{
	free(invalid_memory_access_017_doubleptr_gbl);
}

void invalid_memory_access_017_func_004()
{
	char s[10] ;
	strcpy(s,invalid_memory_access_017_doubleptr_gbl);/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}

void invalid_memory_access_017()
{
	int flag=10;
	if(invalid_memory_access_017_func_001(flag) == 0)
	{
		;
	}
	else
	{
		invalid_memory_access_017_func_002();
	}

	if(invalid_memory_access_017_func_001(flag) == 0)
	{
		;
	}
	else
	{
		invalid_memory_access_017_func_003();
	}

	if(invalid_memory_access_017_func_001(flag) == 0)
	{
		;
	}
	else
	{
		invalid_memory_access_017_func_004();
	}
}