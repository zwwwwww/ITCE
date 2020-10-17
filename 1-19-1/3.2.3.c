/*
From:ITC
3
Inappropriate code
3.2
Improper error handling
3.2.3
Different datatypes in throw and catch statement
*/
void improper_error_handling_003()
{
	try
	{
		float a = 0.0, b = 9.0, c;
		if (a == 0.0)
			throw(a);

		c = b / a;
	}
	catch (int a)
	{
		printf(" Error3
			   : a is equal to 0 % d  \n ", a);
		//exit(1);
	}
}
