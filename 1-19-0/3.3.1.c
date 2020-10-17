/*
From:ITC
3
Inappropriate code
3.3
Improper termination of block 
3.3.1
after if statement 1
*/

void improper_termination_of_block_001()
{
	int condition = 0, x = 0, y = 0;

	if (condition == 0) /*Tool should not detect this line as error*/ /*No ERROR:Improper termination of block*/
	{
		printf(" % d ", x);
	}
	printf(" % d\n ", y);
}
