/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.7
 using Switch case statements and void pointer
*/
         
void *vptr;
int memory_leak_007_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			vptr = (int *)calloc(10, sizeof(int)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
			if(vptr!=NULL)
			{
			   *((int*)vptr+1) = 10;
			}
			return 1;
		}
		case 2:
		{
			vptr = (char *)calloc(10, sizeof(char));
			if(vptr!=NULL)
			{
			   *((char*)vptr+2) = 'a';
			}
			return 2;
		}
		case 3:
		{
			vptr = (float *)calloc(10, sizeof(float));
			if(vptr!=NULL)
			{
			   *((float*)vptr+3) = 5.5;
			}
			return 3;
		}
		default:
			return -1;
	}
}

void memory_leak_007 ()
{
	int ret;
	ret = memory_leak_007_func_001 (rand());
	if(ret >=0 )
		if(vptr!=NULL)
		{
		   free(vptr);
		}
}
