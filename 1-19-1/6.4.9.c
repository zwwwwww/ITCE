/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.9
using a double pointer to char in an infinite while loop
*/
char **free_null_pointer_009dst;
void free_null_pointer_009_func_001()
{
	free_null_pointer_009dst = NULL;
	int i;
    {
		while(0)
		{
			free_null_pointer_009dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	free_null_pointer_009dst[i]=(char*) malloc(15*sizeof(char));
		    }
		    break;
		}
    }
}

void free_null_pointer_009 ()
{
	int i;
    free_null_pointer_009_func_001();
    for(i=0;i<5;i++)
    {
    	strcpy (free_null_pointer_009dst[i],""STRING"");
    }
	while(1)
	{
		for(i=0;i<5;i++)
	    {
			free(free_null_pointer_009dst[i]);
			free_null_pointer_009dst[i] = NULL;
	    }
	    break;
	}
	while(1)
	{
	    free(free_null_pointer_009dst);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	    free_null_pointer_009dst = NULL;
	    break;
	}
}