/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.9
"function : 3 Char pointer arguments and function pointer : two char arguments,one int argument"
*/
  
char wrong_arguments_func_pointer_009_func_001(char *str1, char *str2, char*str3)
{
    strcat(str1,str2);
    strcpy(str3,str1);
	return ('c');
}
void wrong_arguments_func_pointer_009 ()
{
	char *str1 = "STRING";
	char *str2 = "STRING55";
	int *str3 = (int *) malloc(20*sizeof(int));
	char ret;
	char (*func)(char ,char , int *);
	func = (char (*)(char ,char,int*))wrong_arguments_func_pointer_009_func_001;
	ret = func(*str1,*str2,str3);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/

}
