/*
From:ITC
2
Dynamic memory defects
2.1
Deletion of data structure sentinel
2.1.2
string using memcpy function
*/

void deletion_of_data_structure_sentinel_002()
{
	char str1[] =  "This is a string ";
	char str2[16];
	memcpy(str2, str1, strlen(str1)); /*Tool should detect this line as error*/ /*ERROR:Deletion of a data structure sentinel*/
}
