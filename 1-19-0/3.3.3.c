/*
From:ITC
3
Inappropriate code
3.3
Improper termination of block 
3.3.3
Improper termination as the semicolon
*/

void improper_termination_of_block_003()
{
	int x, y = 0;

	for (x = 0; x < 10; x++) /*Tool should not detect this line as error*/ /*No ERROR:Improper termination of block*/
	{
		printf(" % d ", x);
		printf(" % d ", y);
	}
}
