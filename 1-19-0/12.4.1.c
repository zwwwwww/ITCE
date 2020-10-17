/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.1
"Scanf only limits length, not precision"
*/

void invalid_length_001() {
	float a;
	scanf("%f", &a);/*Tool should Not detect this line as error*/ /*ERROR: input/output error*/
}