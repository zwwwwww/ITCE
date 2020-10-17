/*
From:ITC
11
STL defects
11.2
useless calls
11.2.15
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<List>   void useless_call_015() {
	list<int>l = { 8,4,2,9,34,23 };
	l.sort();/*Tool should detect this line as error*/ /*ERROR:STL error*/
}