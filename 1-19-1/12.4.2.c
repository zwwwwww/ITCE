/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.2
"Scanf only limits length, not precision"
*/

void invalid_length_002() {
	float a;
	scanf("%-6.2f", &a);/*Tool should detect this line as error*/ /*ERROR: input/output error*/
}
