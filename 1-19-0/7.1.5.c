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

	if(ptr)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
}
