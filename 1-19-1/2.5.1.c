/*
From:ITC
2
Dynamic memory defects
2.5
Deletion of data structure sentinel
2.5.1
Not leaving a place for '\0'
*/

void deletion_of_data_structure_sentinel_001()
{
	char *foo;
	int counter;
	foo = calloc(10, sizeof(char));
	for (counter = 0; counter < 10; counter++)
	{
		foo[counter] = 'a'; /*Tool should detect this line as error*/ /*ERROR:Deletion of a data structure sentinel*/
	}
	free(foo);
}
