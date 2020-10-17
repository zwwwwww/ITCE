/*
From:ITC
11
STL defects
11.8
"STL if str find
"
11.8.1
find int in string using find()
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                
void STL_if_str_find_001() {
	string s = "abcdefg";
	int a = 1;
	int position;
	position = s.find(a);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}
