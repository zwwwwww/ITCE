/*
From:ITC
11
STL defects
11.2
useless calls
11.2.8
 Call the function to output the elements in the container after clear container
*/
	
using namespace std;	

void useless_call_008() {
	vector<int>v;
	v.push_back(1);
	v.clear();
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
