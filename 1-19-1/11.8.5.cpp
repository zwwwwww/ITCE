/*
From:ITC
11
STL defects
11.8
"STL if str find
"
11.8.5
 find int in string using rfind() function
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                    
void STL_if_str_find_005() {
	string s = "helloworld";
	int a = 0;
	int position;
	position = s.rfind(a);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}
