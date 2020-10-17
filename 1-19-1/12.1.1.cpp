/*
From:ITC
12
Input/Output defects
12.1
Cout Cerr Misusage
12.1.1
 Recursive call without exit using cout output
*/
#include<iostream>	
using namespace std;	
void cout_cerr_001() {
	int a = 1;
	cout << a << endl;/*Tool should detect this line as error*/ /*ERROR:input/output error*/
	if (a = 1) {
		cout_cerr_001();	
	}
}