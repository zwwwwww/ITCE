/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.1
using a pointer to char in an infinite for loop
*/
                     
void memory_leak_001 ()
{
	int i;
	char *buf;
	for (i=0;;i++)
	{
		buf=(char*) calloc(5,sizeof(char)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
		if(buf!=NULL)
		{
			*(buf+1)=1;
		    free (buf);
		}
		if(i>=10)
		break;
	}
}
