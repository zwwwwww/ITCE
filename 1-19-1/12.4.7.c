/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.7
length modifier is too long
*/
	
void invalid_length_007() {
	float f = 1.1;
	printf("%1000000000.000000f", f);/*Tool should detect this line as error*/ /*ERROR: input/output error*/
}
