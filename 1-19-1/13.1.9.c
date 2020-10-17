/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.9
The parameters are related to pointer and array
*/
void Swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
	return;
}
void invalid_function_arg_009() {
	int a[3] = { 3,5,7 };
	int b[2] = { 8.9 };
	Swap(a[0], b[0]);/*Tool should detect this line as eror*/ /*ERROR: API error*/
}
