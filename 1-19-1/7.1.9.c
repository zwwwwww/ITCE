/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.9
Free in a while loop with a variable
*/
   
void double_free_009()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag=0;

	while(flag==0)
	{
		free(ptr);
		flag++;
	}
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}