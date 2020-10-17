/*
From:ITC
2
Dynamic memory defects
2.5
Deletion of data structure sentinel
2.5.3
Not leaving a place for '\0' using memcpy function using a constant
*/

void deletion_of_data_structure_sentinel_003()
{
	int i;
	char ptr[16];
	char str[16];

	for (i = 0; i < 15; i++)
	{
		ptr[i] = 'a';
	}

	ptr[i] = '\0';
	memcpy(str, ptr, 16); /*Tool should detect this line as error*/ /*ERROR:Deletion of a data structure sentinel*/
}
