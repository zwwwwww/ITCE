/*
From:ITC
2
Dynamic memory defects
2.1
Deletion of data structure sentinel
 2.1.3
string using memcpy function with constant
*/

void deletion_of_data_structure_sentinel_003()
{
	int i;
	char str[17];
	char ptr[11];

	for (i = 0; i < 10; i++)
	{
		ptr[i] = 'a';
	}

	ptr[i] = '\0';
	memcpy(str, ptr, 11); /*Tool should Not detect this line as error*/ /*No ERROR:Deletion of a data structure sentinel*/
}
