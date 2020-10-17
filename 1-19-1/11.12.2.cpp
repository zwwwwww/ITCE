/*
From:ITC
11
STL defects
11.12
"Read empty container
"
11.12.2
read empty deque
*/
#include <iostream>
#include <deque>                                                                                                              
using namespace std;                                                                                                        
void read_empty_containers_002() {
	deque<int>temp;
	cout << "First number: " << *temp.begin() << "\n";// /*Tool should detect this line as error*/ /*ERROR:STL error*/
}   