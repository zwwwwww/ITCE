/*
From:ITC
11
STL defects
11.8
"STL if str find
"
11.8.4
find int in string using find_first_not_of() function
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                          
void STL_if_str_find_004() {
	string s = "helloworld";
	int a = 1;
	int position;
	position = s.find_first_not_of(a);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}
