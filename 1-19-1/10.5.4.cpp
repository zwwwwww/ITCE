/*
From:ITC
10
Simple type defects
10.5
string
10.5.4
Comparison of identical string variables
*/

using namespace std;                                                                                                            
void string_004() {
	string s = "hello";
	if (s =s)/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
		cout << s;
	else
		return;
}
