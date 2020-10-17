/*
From:ITC
11
STL defects
11.14
"Iterators
"
11.14.1
Iterator out of range
*/
#include<cstring>
void Iterator_out_of_range_001(std::string &str, char ch)
{
	for (std::string::const_iterator iter = str.begin(), end = str.end();
		iter != end; ++iter)
	{
		if (*(iter + 1) == ch)/*Tool should detect this line as error*/ /*ERROR:STL error*/
		{
		}
	}
}
