/*
From:ITC
11
STL defects
11.3
"use auto pointer
"
11.3.1
"""auto"" be used to deduce raw pointer"
*/
#include<iostream>
using namespace std;                                                                                                                 
class Item {
private:
	int i;
};
void use_auto_pointer_001() {
	auto* item = new Item();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}