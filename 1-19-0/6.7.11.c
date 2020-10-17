/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.11
using a unsigned int pointer and partially initialized in a infinite loop
*/
              
void uninit_pointer_011 ()
{
    unsigned int * ptr = NULL,a=0;
    ptr = (unsigned int *)malloc(10*sizeof(unsigned int *));
    int i;
	if (ptr!=NULL)
	{
		while(1)
       {
           for(i=0; i<10; i++)
           {
            	ptr[i] = i;
           }
           break;
       }
       while(1)
       {
          for(i=0; i<10; i++)
          {
        	  a += ptr[i]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
          }
          break;
       }
	}
}
