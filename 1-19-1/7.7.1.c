/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.1
 using unsigned long variable - stack access
*/
     
void uninit_memory_access_001 ()
{
	unsigned long a;
	unsigned long *ret;
	ret = &a;
    printf("%ld ",*ret);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
}