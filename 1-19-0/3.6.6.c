/*
From:ITC
3
Inappropriate code
3.6
Unused variable
3.6.6
"basic types	static variable in the Function"
*/

void unused_var_006()
{
	static int a = 1;
	static int b = 2;
	static int unuse;
	if (a == 1)
	{
		unuse = a + b;
		printf(" % d ", unuse); /*Tool should not detect this line as error*/ /*No ERROR:Unused variable*/
	}
}
