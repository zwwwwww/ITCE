/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.5
nocompliant identifier
*/
                                                                                                             
#define 3a  "Jacky"    /*Tool should detect this line as error*/ /*ERROR:Macros error*/   
void constant_macros_005() {
	printf("%s", 3a);
}
