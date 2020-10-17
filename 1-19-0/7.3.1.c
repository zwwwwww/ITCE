/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.1
 Memory is allocated and accessed after free -  when using pointer to int and conditional operator
*/
                                    
void invalid_memory_access_001 ()
{
	int *ptr, a;
	int flag=10;

    (flag == 10)? (ptr= (int*) malloc(10*sizeof(int))) : ( ptr= NULL);

    if(ptr!=NULL)
    {
    	(flag == 10)? (*(ptr+1) = 10):(a=100);
        if(flag == 10)
        {
        	a = *(ptr+1); /*Tool should not detect this line as error*/ /*No ERROR:Invalid memory access to already freed area*/
        	printf(""%d"",a);
       }
        if(flag == 10)
        {
        	free(ptr);
    	    ptr = NULL;
         }
     }
}
