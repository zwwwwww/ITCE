/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.6
The parameters are related to array
*/
int average(float score[10]) {
	int i;
	float sum=0.0;
	for (i = 0; i < 10; i++) {
		sum = sum + score[i];
	}
	return sum / 10;
}
void invalid_function_arg_006() {
	float score[10] = { 70.3,76.4,65.0,78.2,98.5,89.0,67.5,64.7,95.5,88.0 };
	average(score[10]);/*Tool should detect this line as eror*/ /*ERROR: API error*/
}
