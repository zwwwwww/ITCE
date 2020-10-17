/*
From:ITC
3
Inappropriate code
3.2
Improper error handling
3.2.2
Improper error handling due to no code presence in catch
*/
void improper_error_handling_002()
{
	try
	{
		int a = 0, b = 9, c;
		if (a == 0)
			throw(a);
		c = b / a;
	}
	catch (int a)
	{
		printf("Error2: a is equal to 0 %d  \n", a);
	}
}
