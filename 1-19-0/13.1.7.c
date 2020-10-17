/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.7
The parameters are related to pointer
*/
void Swap(int* p, int* q){
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
	return;
}
void invalid_function_arg_007() {
	int x = 3;
	int y = 7;
	Swap(&x, &y); /*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
