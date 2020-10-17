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
    strcpy(str1,str2);
    strcpy(str3,str1);
    return ('c');
}

void wrong_arguments_func_pointer_009 ()
{
  char *str1 = strdup("STRING33");
  if (!str1) return;
  char *str2 = strdup("STRING55");
  if (!str2) return;
  char *str3 = (char *) malloc(20*sizeof(char));
  if (!str3) return;
  char ret;
  char (*func)(char *,char *, char *);
  func = wrong_arguments_func_pointer_009_func_001;
  ret = func(str1,str2,str3); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
  free(str1);
  free(str2);
  free(str3);
}
