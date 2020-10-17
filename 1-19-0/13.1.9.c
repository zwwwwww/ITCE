/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.9
The parameters are related to pointer and array
*/
void Swap(int* p, int* q){
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
	return;
}
void invalid_function_arg_009() {
	int a[3] = { 3,5,7 };
	int b[2] = { 8,9 };
	Swap(a, b);/*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
