/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.7
fclose() without position
*/
	
void IO_without_007() {
	FILE* fp;
	fclose(fp);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}