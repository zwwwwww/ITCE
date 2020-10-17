/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.5
Memory is free in a if statement
*/
     
void double_free_005()
{
	char* ptr= (char*) malloc(sizeof(char));
	free(ptr);

	if(ptr)
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}