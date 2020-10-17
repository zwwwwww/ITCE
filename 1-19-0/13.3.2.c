/*
From:ITC
13
"API defects
"
13.3
Obsolete function
13.3.2
obsolete POSIX functions
*/

void obsolete_function_002() {
	unsigned int seed;
	seed = rand()%50;/*Tool should Not detect this line as error*/ /*ERROR:API error*/
	printf("%d", seed);
}
