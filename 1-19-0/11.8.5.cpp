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
	string s1="hello";
	int position;
	position = s.rfind(s1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}