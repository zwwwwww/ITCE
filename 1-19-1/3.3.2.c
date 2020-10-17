/*
From:ITC
3
Inappropriate code
3.3
Improper termination of block 
3.3.2
after if statement 2
*/

void improper_termination_of_block_002()
{
	int condition = 0, x = 0, y = 0;

	if (condition == 0)
		;
	printf(" % d ", x); /*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	printf(" % d ", y);
}
