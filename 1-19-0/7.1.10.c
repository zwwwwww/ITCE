/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.10
Free in a while loop with a constant
*/
                      
void double_free_010()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag=1;

	while(flag)
	{
		free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
		flag--;
	}
}
