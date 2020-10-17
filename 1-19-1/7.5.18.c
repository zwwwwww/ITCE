/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.18
using a double pointer to char in an infinite while loop
*/
         
char **memory_leak_0018dst;
void memory_leak_0018_func_001()
{
	memory_leak_0018dst = NULL;
	int i;
    {
		while(1)
		{
			memory_leak_0018dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	memory_leak_0018dst[i]=(char*) malloc(15*sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
		    }
		    break;
		}
    }
}

void memory_leak_0018 ()
{
	int i;
    memory_leak_0018_func_001();
    for(i=0;i<5;i++)
    {
    	strcpy (memory_leak_0018dst[i],"STRING");
    }
	while(1)
	{
		for(i=0;i<5;i++)
	    {
                ;

	    }
	    free(memory_leak_0018dst);
	    memory_leak_0018dst = NULL;
	    break;
	}
}