/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.4
Identifier expected
*/
                                                                                                                 
#define 3.14    /*Tool should detect this line as error*/ /*ERROR:Macros error*/   
float constant_macros_004() {
	int r = 3;
	return 3.14 * r;
}

