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
	float (*func)(float*);
	float i=10.5;
	float *buf = &i;
	float ret;
	func = (float (*)(float * ))wrong_arguments_func_pointer_005_func_001;
	ret = func(buf);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/

}
