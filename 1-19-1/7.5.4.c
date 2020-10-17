/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.4
using pointers to the structure with an string as a member of the structure
*/
  
typedef struct {
	int a;
	int b;
	char *buf;
} memory_leak_004_s_001;

void memory_leak_004 ()
{
	memory_leak_004_s_001* s=(memory_leak_004_s_001*) calloc(5,sizeof(memory_leak_004_s_001)) ;
	char *s1=""This is a string"";
	int i;
	if(s!=NULL)
	for(i= 0; i<5 ;i++)
	{
		(s+i)->buf = (char*)malloc(25* sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	}
	strcpy((s+4)->buf,s1);
	for(i= 0; i<5 ;i++);
	free(s);
}