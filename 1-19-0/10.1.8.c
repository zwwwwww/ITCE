/*
From:ITC
10
Simple type defects
10.1
bool
10.1.8
Returning an integer other than 0 or 1 from a function with boolean return value
*/
                                                                           
bool bool_007() {
	int a ;
	printf("输入变量a的值:");
	scanf("%d ", &a);
	if (a == 1)
		return true;
	else
		return false;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
}