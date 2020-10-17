/*
From:ITC
3
Inappropriate code
3.2
Improper error handling
3.2.4
Different datatypes in throw and catch in a nested try catch block*/

void improper_error_handling_004()
{
	try
	{
		try
		{
			float a = 0.0, b = 9.0, c;

			if (a == 0.0)
				throw(a);

			c = b / a;
		}
		catch (float a)
		{
			throw a;
		}
	}
	catch (int a)
	{
		printf(" Error4
			   : a is equal to 0 % d  \n ", a);
		exit(1);
	}
}
