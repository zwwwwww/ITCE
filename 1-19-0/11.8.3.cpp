/*
From:ITC
11
STL defects
11.8
"STL if str find
"
11.8.3
out of find range
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                             
void STL_if_str_find_003() {
	string s = "sihbfdhkfb";
	string s1 = "hk";
	int position;
	position = s.find(s1, 1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	cout << position;
}