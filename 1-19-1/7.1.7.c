/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.7
Memory is free in a variable if statement
*/
    
void double_free_007()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag=0;
	
	if(flag>=0)
	free(ptr);

	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}