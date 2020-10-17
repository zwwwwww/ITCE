/*
From:ITC
3
Inappropriate code
3.3
Improper termination of block 
3.3.4
after while statement
*/

void improper_termination_of_block_004()
{
	int x = 0, y = 0;

	while (x < 10)
		; /*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	x++;
	printf(" % d ", x);
	printf(" % d ", y);
}
