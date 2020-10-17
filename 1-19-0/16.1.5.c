/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.5
nocompliant identifier
*/
 
#define NAME  "Jacky"    /*Tool should Not detect this line as error*/ /*ERROR:Macros error*/   
void constant_macros_005() {
	printf("%s", NAME);
}

