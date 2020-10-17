/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.16
 global char double pointer int variable initialized in another function
*/
   
char ** uninit_pointer_016_gbl_doubleptr;
int uninit_pointer_016_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void uninit_pointer_016_func_002()
{
	int i;
	if(uninit_pointer_016_func_001(0)==0)
	{
		uninit_pointer_016_gbl_doubleptr=(char**) malloc(10*sizeof(char*));
    	for(i=0;i<10;i++)
	    {
    		uninit_pointer_016_gbl_doubleptr[i]=(char*) malloc(10*sizeof(char));
			if(i<5)
    		   strcpy(uninit_pointer_016_gbl_doubleptr[i],""STRING00"");
	    }
	}
}

void uninit_pointer_016()
{
	int flag=0,i;
	char *s=(char*) malloc(10*sizeof(char));
	if(uninit_pointer_016_func_001(flag)==0)
	{
		uninit_pointer_016_func_002();
	}

	if(uninit_pointer_016_gbl_doubleptr!=NULL)
	{
		for(i=0;i<10;i++)
		{
			if(uninit_pointer_016_gbl_doubleptr[i] !=NULL)
			{
				if(i==7)
				    strcpy(s,uninit_pointer_016_gbl_doubleptr[i]);/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
			free (uninit_pointer_016_gbl_doubleptr[i]);
			}
	    }
	    free(uninit_pointer_016_gbl_doubleptr);
	    free(s);
	}
}