/*
From:ITC
13
API defects
13.5
Unprecise call
13.5.1
 Ignore the case of the name of the called function
*/
                                                                                            
int  FUNC_001(int i) {
	return i;
}
void unprecise_call_001() {
	func_001(2);/*Tool should detect this line as error*/ /*ERROR: API error*/
}
