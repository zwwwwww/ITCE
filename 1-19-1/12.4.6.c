/*
From:ITC
12
Input/Output defects
12.4
Invalid Length Modifier Error
12.4.6
float type length modifier has Other characters 
*/

void invalid_length_006() {
	float f = 1.1;
	printf("%$2.1f", f);/*Tool should detect this line as error*/ /*ERROR: input/output error*/
}