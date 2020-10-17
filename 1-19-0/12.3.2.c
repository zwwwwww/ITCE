/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.2
getc() without position
*/

void IO_without_002() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "r");
	int getc(fp);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}