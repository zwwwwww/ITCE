/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.7
"using double pointers to the type char 2D array of size [5][15] ,strcpy"
*/
         
void invalid_memory_access_007 ()
{
	char **ptr = (char**) malloc(5*sizeof(char*));
	int i;

	for(i=0;i<5;i++)
		ptr[i]=(char*) malloc(15*sizeof(char));

	for(i=0;i<5;i++)
	{
		strcpy(*(ptr+i),""String"");
	    free(ptr[i]);
	    ptr[i] = NULL;
	}
	free(ptr);
	strcpy(*(ptr+2),""String""); /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}