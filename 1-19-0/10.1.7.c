/*
From:ITC
10
Simple type defects
10.1
bool
10.1.7
Comparison of a boolean expression with an integer other than 0 or 1
*/
                                                                         
int bool_006() {
	bool a = false;
	if (a == (1 > 2))/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
		return 1;
	else
		return 0;
}