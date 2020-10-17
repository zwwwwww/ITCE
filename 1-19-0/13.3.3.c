/*
From:ITC
13
"API defects
"
13.3
Obsolete function
13.3.3
Deprecated K&R syntax should not be used for function definition
*/

int obsolete_function_003(int a,char *b) {// Noncompliant K&R C syntax
	printf("%d %c", a, b);/*Tool should Not detect this line as error*/ /*ERROR:API error*/
}
