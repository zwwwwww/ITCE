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
#include <dequer>                                                                                                                          
using namespace std;                                                                                                           
void read_empty_containers_002() {
	deque<int>temp;
	temp.push_front(3);
	cout << "First number: " << *temp.begin() << "\n";// /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}