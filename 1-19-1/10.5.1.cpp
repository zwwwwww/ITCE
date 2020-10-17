/*
From:ITC
10
Simple type defects
10.5
string
10.5.1
String literal compared with variable foo
*/
using namespace std;                                                                                                              
void string_001() {
	string s = "helloworld";
	int foo = 3;
	if (s = foo)/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
		cout << "s=" << s;
	else
		cout << "foo=" << foo ;
}
