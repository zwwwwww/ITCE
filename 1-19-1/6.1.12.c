/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.12
pointer to array of Int * and typedef and function pointer: float *
*/
       
typedef int (*pointertoarr)[4];
int (*func_pointer_012_func_001())[4]
{
	int (*p)[4];
	int arr[4][4] = {{1,2,3,4},
			         {11,22,33,44},
			         {33,44,55,66},
			         {55,66,77,88}};
	int i,j;
	p= (int (*)[]) malloc (sizeof arr);
	memcpy(p, arr, sizeof(arr));
	for (i = 0;i< 4; i++)
	{
		for ( j=0 ;j<4; j++)
		{
			*(p[i]+j) += *(p[i]+j);
		}
	}
	return p;
}

void func_pointer_012 ()
{
	int (*ptr)[4];
	float *(*func)();
	func = (float *(*)(void))func_pointer_012_func_001;
	ptr = (int (*)[]) func();/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
	free(ptr);
}