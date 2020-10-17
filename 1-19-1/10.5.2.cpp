/*
From:ITC
10
Simple type defects
10.5
string
10.5.2
String literal Hello World doesnt match length argument for substr()
*/

using namespace std;                                                                                                                       
void string_002() {
	string s = "hello world";
	string s1 = s.substr(20);/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	cout << s1;
}