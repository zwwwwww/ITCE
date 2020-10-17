/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.5
function : char * and function pointer : float *
*/
float wrong_arguments_func_pointer_005_func_001 (char *p)
{
	float f=20.5;
	if((strcmp(p,"string")) == 0)
	{
		f++;
	}
	return (f);
}

void wrong_arguments_func_pointer_005 ()
{
    float (*func)(char*);
	char buf[10] = "string";
	float ret;
	func = wrong_arguments_func_pointer_005_func_001;
	ret = func(buf); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
