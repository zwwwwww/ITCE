/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.13
"function : int, char double pointer and function pointer :char pointer"
*/
    
void wrong_arguments_func_pointer_013_func_001 (int len,char **stringPtr)
{
	char * p = malloc(sizeof(char) * (len+1));
	*stringPtr = p;
}

void wrong_arguments_func_pointer_013 ()
{
 	char *str = "This is a string";
	char *str1;
	void (*fptr)(int,char **);
	fptr = wrong_arguments_func_pointer_013_func_001;
	fptr(strlen(str),&str1); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
	strcpy(str1,str);
	free(str1);
	str1 = NULL;
}
