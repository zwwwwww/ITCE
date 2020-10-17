/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.4
Identifier expected
*/
      
#define PI 3.14    /*Tool should Not detect this line as error*/ /*ERROR:Macros error*/   
float constant_macros_004() {
	int r = 3;
	return PI * r;
}
