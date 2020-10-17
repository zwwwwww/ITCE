/*
From:ITC
3
Inappropriate code
3.2
Improper error handling
3.2.1
No throw function in a try catch block
*/
void improper_error_handling_001()
{
	try
	{
		int a = 0, b = 9, c;
		if (a == 0)
			c = b / a;
	}
	catch (int a)
	{
		printf("Error1: a is equal to 0 %d  \n", a);
		//exit(1);
	}
}
