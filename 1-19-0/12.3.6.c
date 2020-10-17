/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.6
fgets() without position
*/
	
void IO_without_006() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "r");
	char* s = "abc";
	int n = 1;
	char* fgets(s, n, fp);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
}