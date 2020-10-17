/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.16
"function : 3 Char pointer arguments and function pointer : two char arguments,one int argument"
*/
     
char wrong_arguments_func_pointer_016_func_001(char *str1, int *str2, float*str3)
{
  char s[20];
  strcpy(s,str1);
  *str2 +=1;
  *str3 +=1;
  return (*str2);
}
void wrong_arguments_func_pointer_016 ()
{
    char *str1 = "STRING";
	int a=10,*str2 = &a;
	float f=20.5,*str3 = &f;
	char ret;
	char (*func)(char *,float *,int * );
	func = (char (*)(char*,float*,int*))wrong_arguments_func_pointer_016_func_001;/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
	ret = func(str1,str3,str2);
}"
