/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.11
"1-dimensional array	int	Function arguments	Loading and
 * initialized with return value of function"
*/

extern int sink;
int uninit_var_011_func_001(int arr1[], int a)
{
	int ret = 0;
	if (arr1[0] > 0)
		ret = a + arr1[1]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	return ret;
}

void uninit_var_011()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int p;
	p = uninit_var_011_func_001(arr, (sizeof(arr) / sizeof(int)));
	sink = p;
}
