/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.5
fputs() without position
*/
	
void IO_without_005() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w");
	char* s = "abc";
	int fputs(s, fp);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}