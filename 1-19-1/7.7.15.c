/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.15
" using a pointer to array of Int, memory allocated and initialized using memcpy by return value of function"
*/
    
int (*uninit_memory_access_015_func_001())[4]
{
	int (*p)[4];
	int arr[4][4];
	int i,j;
	p= (int (*)[]) malloc (sizeof arr);
	memcpy(p, arr, sizeof(arr));
	for (i = 0;i< 4; i++)
	{
		for ( j=0 ;j<4; j++)
		{
			*(p[i]+j) += *(p[i]+j);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
		}
	}
	return p;
}

void uninit_memory_access_015 ()
{
	int (*ptr)[4];
	ptr = uninit_memory_access_015_func_001();
	free(ptr);
	ptr = NULL;
}