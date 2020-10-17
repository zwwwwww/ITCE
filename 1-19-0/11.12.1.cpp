/*
From:ITC
11
STL defects
11.12
"Read empty container
"
11.12.1
read empty vector
*/
#include <iostream>
#include <vector>                                                                                                           
 using namespace std;                                                                                                                        
  void read_empty_containers_001() {
	vector<int>vec;
	vec.push_back(1);
	cout << "First number: " << *vec.begin() << "\n";// /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}