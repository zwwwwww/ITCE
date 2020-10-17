/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.3
int type length modifier has Other characters 
*/

void invalid_length_003() {
	int a;
	scanf("%#6d", &a);/*Tool should detect this line as error*/ /*ERROR: input/output error*/
}
