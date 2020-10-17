/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.7
using a global pointer to char in a for loop inside if condition
*/
          
#define MAX_VAL 10            
static unsigned int static_var = MAX_VAL*2;
static char * memory_allocation_failure_007_func_001 (char *str1)
{
    int j;
    if (str1 != NULL)
    {
    	static_var = strlen(str1);
        memory_allocation_failure_007_str_gbl = (char *) malloc(static_var+1); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
        if(memory_allocation_failure_007_str_gbl!=NULL)
        {
        for (j = 0; j < static_var; j++)
        {
            memory_allocation_failure_007_str_gbl[j] = str1[static_var-j-1];
        }
        memory_allocation_failure_007_str_gbl[static_var] = '\0';
        }
        return memory_allocation_failure_007_str_gbl;
    }
    else
    {
        return NULL;
    }
}

void memory_allocation_failure_007 ()
{
    int j;
    char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        if(buf[j]!= NULL)
    	{
        	memory_allocation_failure_007_str_gbl = memory_allocation_failure_007_func_001(buf[j]);
        }
    }
}
