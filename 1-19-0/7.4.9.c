/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.9
using a pointer to char in a do ~ while loop and memory allocate and returned to another function
*/
        
#define MAX_VAL 10             
#define MAX_BUFFER (429496728UL)

void memory_allocation_failure_009_func_001 (char * buf)
{
    int i=0;
    do
    {
    	buf = (char*) malloc(MAX_BUFFER * sizeof(char)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
    	i++;
    }while (i<MAX_VAL);
}

void memory_allocation_failure_009_func_002 (void * vptr)
{
	/* cast void pointer to a pointer of the appropriate type */
    char * * cptr = (char * *)vptr;
    char * buf =NULL;
    memory_allocation_failure_009_func_001 (buf);
    buf = (*cptr);
    printf("%s",buf);
}

void memory_allocation_failure_009 ()
{
    void *buf1;
	buf1 = "String Test123";
    memory_allocation_failure_009_func_002(&buf1);
}
