/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.14
using a pointer to int and  goto
*/
      
int invalid_memory_access_014 (int flag)
{
	int ret = 0,i;
	int arr[]={3,8,9,10,4};
	int *ptr = malloc(sizeof(int)*5);
	if (flag == 1)
	{
		goto my_label;
	}
	if(ptr!=NULL)
	{
   		goto my_label2;
        ret = ptr[2];/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/

	}
my_label:
	    {
            for(i=0;i<5;i++)
            {
            	if(ptr!=NULL)
            		ptr[i] = arr[i];
            }

	    }
my_label2:
    free(ptr);
	return ret;
}