/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.8
function : one float argument and function pointer : two char pointer arguments
*/
float wrong_arguments_func_pointer_008_func_001(float a )
{
	a--;
	return a;
}
void wrong_arguments_func_pointer_008 ()
{
    float a = 11.5;
	float ret;
	func_glb = wrong_arguments_func_pointer_008_func_001;
	ret = func_glb(a); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
