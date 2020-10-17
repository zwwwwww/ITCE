/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.4
Memory is free in a if statement
*/
       
void double_free_004()
{
	char* ptr= (char*) malloc(10*sizeof(char));
	int i;
	for(i=0;i<10;i++)
	{
		*(ptr+i)='a';
	}

	if (rand() % 2==0)
	{
		free(ptr);
	}

	if(rand() % 3==0)
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}