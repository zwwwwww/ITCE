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
		unuse = a + b; /*Tool should detect this line as error*/ /*ERROR:Unused variable*/
	}
}
