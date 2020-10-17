/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.11
double Free in a while loop with a condition
*/

void double_free_011()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag=1,a=0,b=1;

	while(a<b)
	{
		if(flag ==1)
		free(ptr);  /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
		a++;
	}
}
