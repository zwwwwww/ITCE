/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.11
Warn on uses of the ¡®gets¡¯ function
*/
void invalid_function_arg_011() {
	char buff[20]="\0";
	scanf("%s", buff);
	gets(buff);/*Tool should detect this line as eror*/ /*ERROR: API error*/
	printf("%s", buff);
}
