/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.12
double Free in a for loop
*/
          
void double_free_012()
{
	char* ptr= (char*) malloc(sizeof(char));
	int a=0;

	for(a=0;a<1;a++)
	{
		free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
	}
}
