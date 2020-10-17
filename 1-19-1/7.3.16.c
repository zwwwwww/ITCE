/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.16
 global char double pointer  variable initialized in another function
*/
           
char ** invalid_memory_access_016_doubleptr_gbl;   
int invalid_memory_access_016_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void invalid_memory_access_016_func_002()
{
	int i;
	if(invalid_memory_access_016_func_001(0)==0)
	{
		invalid_memory_access_016_doubleptr_gbl=(char**) malloc(10*sizeof(char*));
    	for(i=0;i<10;i++)
	    {
    		invalid_memory_access_016_doubleptr_gbl[i]=(char*) malloc(10*sizeof(char));
    		   strcpy(invalid_memory_access_016_doubleptr_gbl[i],""STRING00"");
	    }
	}
}

void invalid_memory_access_016_func_003()
{
	char s[10] ;
	strcpy(s,invalid_memory_access_016_doubleptr_gbl[0]);/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}

void invalid_memory_access_016()
{
	int flag=0,i;
	if(invalid_memory_access_016_func_001(flag)==0)
	{
		invalid_memory_access_016_func_002();
	}

	if(invalid_memory_access_016_doubleptr_gbl!=NULL)
	{
		for(i=0;i<10;i++)
		{
			if(invalid_memory_access_016_doubleptr_gbl[i] !=NULL)
			free (invalid_memory_access_016_doubleptr_gbl[i]);
	    }
	    free(invalid_memory_access_016_doubleptr_gbl);
	}
	if(invalid_memory_access_016_func_001(flag)==0)
	{
		invalid_memory_access_016_func_003();
	}
} 