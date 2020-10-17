/*
From:ITC
4
Misc defects
4.5
Useless assignment 
4.5.1
a pointless assignment
*/

int rand(void);
void insign_code_001()
{
	int i;
	int j;

	i = rand();
	j = i - 1;
	i = j - 1; /*Tool should not detect this line as error*/ /*No ERROR:Useless Assignment */
	printf(" % d ", i);
}
