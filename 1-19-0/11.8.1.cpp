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
	string s1 = "a";
	int position;
	position = s.find(s1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}