/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.9
char array Function arguments
*/

extern int sink;
void uninit_var_009_func_001(char buf[])
{
	char ret[] = " This is a string ";
	strcpy(buf, ret); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
}

void uninit_var_009()
{
	char buf[25];
	uninit_var_009_func_001(buf);
}
