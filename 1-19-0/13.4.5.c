/*
From:ITC
13
"API defects
"
13.4
Wrong call
13.4.5
Case of letter in function name
*/
double abc(double x, double y) {
	return (x + y);
}
void wrong_call_005() {
	double x = 2.12, y = 3.34;
	abc(x, y);  /*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
}
