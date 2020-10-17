/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.3
" Basic type where pointer is ""freed"" in a loop and then outside the loop"
*/
           
void double_free_003()
{
	char* ptr= (char*) malloc(10*sizeof(char));
	int i;
	
	for(i=0;i<10;i++)
	{
		*(ptr+i)='a';
		
	}

	free(ptr);  /*Tool should Not detect this line as error*/ /*No ERROR:Double free*/
}
