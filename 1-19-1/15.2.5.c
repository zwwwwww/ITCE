/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.5
read uninitialized memory
*/

void set_flag(int number, int* sign_flag) {
	if (NULL == sign_flag) {
		return;
	}

	if (number > 0) {
		*sign_flag = 1;
	}
	else if (number < 0) {
		*sign_flag = -1;
	}
}
int undefined_behavior_005() {
	int number; 
	int sign;
	set_flag(number, &sign);
	return sign < 0;
}
