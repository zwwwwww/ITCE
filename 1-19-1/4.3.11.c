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

int uninit_var_011_func_001(int arr1[], int a)
{
	int ret = 0;
	if (arr1[0] > 0)
		ret = a + arr1[1]; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	return ret;
}

void uninit_var_011()
{
	int arr[5];
	int p;
	p = uninit_var_011_func_001(arr, (sizeof(arr) / sizeof(int)));
}
