/*
From:ITC
10
Simple type defects
10.1
bool
10.1.1
boolean value assigned to pointer
*/
                                                                           
bool f(int x, int y) {
	if (x > y) {
		return true;
	}
	else
		return false;
}                                                                                                                
void bool_001() {
	int* p;
	p = f(3, 5);/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
