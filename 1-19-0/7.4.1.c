/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.1
using a pointer to long in an infinite for loop
*/
void memory_allocation_failure_001 ()
{
	int i;
	long *buf;
	for (i=0;;i++)
	{
		buf=(long*) calloc(5,sizeof(long));
		if(buf !=NULL)
		{
			buf[1]=1; /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
		    free (buf);
		}
		if(i>=MAX_VAL)
		break;
	}
}
