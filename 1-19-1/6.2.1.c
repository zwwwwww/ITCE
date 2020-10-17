/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.1
function : int and function pointer :int *
*/

int wrong_arguments_func_pointer_001_func_001(int a)
{
    int i=10;
	return (i);
}

void wrong_arguments_func_pointer_001 ()
{
	int arr[5] = {1,2,3,4,5} ;
	int (*fptr)(int *);
	int a;
	fptr = (int (*)(int *))wrong_arguments_func_pointer_001_func_001;
	a =fptr(arr);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
}
