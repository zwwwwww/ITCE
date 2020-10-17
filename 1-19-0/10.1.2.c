/*
From:ITC
10
Simple type defects
10.1
bool
10.1.2
boolean value assigned to float
*/
                                                                           
bool f(int x, int y) {
	if (x > y) {
		return true;
	}
	else
		return false;
}                                                                                                               
void bool_002() {
	bool a;
	a = f(7, 3);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
} 