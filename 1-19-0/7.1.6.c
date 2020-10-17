/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.6
Memory is free in a constant if statement
*/
      
void double_free_006()
{
	char* ptr= (char*) malloc(sizeof(char));
	if(0)
	free(ptr);

	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
}
