/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.11
1-dimensional array
*/
      
void invalid_memory_access_011 ()
{
	int *ptr,i=0,j;
	int index[4] = {3, 5, 4, 6};
	for(j=0;;j++)
	{
		ptr = (int *)malloc(sizeof(int) * 4);
		if(ptr!=NULL)
		{
		   while(i<4)
		   {
			   ptr[i] = index[i];
	           i++;
	       }
	       free(ptr);
		}
	    if(j>10)
	    break;
	}
	 *(ptr+i) = i; /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}
