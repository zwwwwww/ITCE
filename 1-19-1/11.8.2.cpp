/*
From:ITC
11
STL defects
11.8
"STL if str find
"
11.8.2
Finds the address of the first occurrence of a string in a string 
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                          
void STL_if_str_find_002() {
	string s = "dnjmfngl";
	string s1 = "abc";
	int position;
	position = s.find_first_of(s1);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}
