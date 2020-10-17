/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.12
"using a pointer array of int , memory allocated in another function based on return value of a function in a ternary statement"
*/
   
#define MAX_VAL 10        
int *memory_allocation_failure_012_buf2_gbl;
int memory_allocation_failure_012_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_012_func_002 (int *pbuf[])
{
	int buf1[5] = {1,2,3,4,5};
	memory_allocation_failure_012_buf2_gbl = (int *) calloc (memory_allocation_failure_012_func_001(0),sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
	int buf3[5] = {1,2,3,4,5};
	int buf4[5] = {1,2,3,4,5};
	int buf5[5] = {1,2,3,4,5};
	pbuf[0] = buf1;
	pbuf[1] = memory_allocation_failure_012_buf2_gbl;
	pbuf[2] = buf3;
	pbuf[3] = buf4;
	pbuf[4] = buf5;
	int ret;
	ret = pbuf[1][1];
	printf("%d",ret);
}

void memory_allocation_failure_012 ()
{
	int *ptr[5], a;
	int flag=10;

    (flag == 10)? (memory_allocation_failure_012_func_002(ptr)) : ( a =20);
    (flag == 10)? (ptr[1][1] = 200):(a=100);

    if(flag == 10){
    	if(memory_allocation_failure_012_buf2_gbl!=NULL)
    	{
    		a = ptr[1][1];
    	    free(memory_allocation_failure_012_buf2_gbl);
    	}
    }
}