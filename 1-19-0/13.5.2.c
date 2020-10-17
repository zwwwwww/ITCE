/*
From:ITC
13
API defects
13.5
Unprecise call
13.5.2
 Ignore the case of the name of the called function
*/
                                                                                                     
void func_002() {
	printf("helloworld");
}
void unprecise_call_002() {
	func_002();/*Tool should Not detect this line as error*/ /*ERROR:API error*/
}
