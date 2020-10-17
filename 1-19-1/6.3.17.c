/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.17
When using a double pointer to char in an infinite while loop
*/
   
char **null_pointer_017dst;

void null_pointer_017_func_001(int flag)
{
	null_pointer_017dst = NULL;
	int i;
    {
		while(flag)
		{
			null_pointer_017dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	null_pointer_017dst[i]=(char*) malloc(15*sizeof(char));
		    }
		    break;
		}
    }
}

void null_pointer_017 ()
{
	int i;
    null_pointer_017_func_001(0);
    for(i=0;i<5;i++)
    {
    	strcpy (null_pointer_017dst[i],"STRING");/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
    }
	while(1)
	{
		for(i=0;i<5;i++)
	    {
			free(null_pointer_017dst[i]);
			null_pointer_017dst[i] = NULL;
	    }
	    free(null_pointer_017dst);
	    null_pointer_017dst = NULL;
	    break;
	}
}
