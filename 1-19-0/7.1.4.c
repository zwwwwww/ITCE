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
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
}
