/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.13
Double int pointer partially initialized with 2D array
*/

void uninit_pointer_013 ()
{
	int **ptr = (int**) malloc(5*sizeof(int*));
		int i,j;

		for(i=0;i<5;i++)
			ptr[i]=(int*) malloc(5*sizeof(int));
	    int arr[3][3] = {{1,2,3},
				         {11,12,13},
		                 {21,22,23}};

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				*(*(ptr+i)+j)= arr[i][j];/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
			}
		    free(ptr[i]);
		    ptr[i] = NULL;
		}
		free(ptr);
		ptr = NULL;
}