/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.5
The float type output length is 0
*/
	
void invalid_length_005() {
	float f = 1.3333333;
	printf("%0.0f", f);/*Tool should detect this line as error*/ /*ERROR: input/output error*/
}
