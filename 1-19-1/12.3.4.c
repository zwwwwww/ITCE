/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.4
putc() without position
*/
	
void IO_without_004() {
	FILE* fp;
	int c;
	int putc(c, fp);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}