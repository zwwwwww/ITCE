/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.4
using double short pointer and aliasing
*/
  
void uninit_memory_access_004 ()
{
	short **ptr = NULL;
	short *p1 = (short *) calloc(10,sizeof(short));
	short *p2 = NULL;
	if(p1 !=NULL)
	{
     p2 = p1;
	}
     ptr = &p2;
     printf("%d \n",**ptr);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
     free(p1);
}