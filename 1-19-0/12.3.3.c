/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.3
fputc() without position
*/

void IO_without_003() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w");
	int c;
	int fputc(c, fp);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}
