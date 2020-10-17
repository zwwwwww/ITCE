/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.5
 using a pointer to int in a recursive function
*/
        
int invalid_memory_access_005 (int count)
{
	int *ptr ;

	if (count ==0)
	{
    	count = *ptr; /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
		return 1;
	}
    else
    {
    	ptr = (int *) calloc (count,sizeof(int));
    	if(ptr!=NULL)
    	{
    		*(ptr+(count-1)) = 5*count;
    	    free(ptr);
    	}
    	return (count * invalid_memory_access_005(count-1));
    }
}