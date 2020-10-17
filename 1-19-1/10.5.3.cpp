/*
From:ITC
10
Simple type defects
10.5
string
10.5.3
Char literal compared with pointer foo
*/

using namespace std;                                                                                                               
void  strin g_ 00 3( )  {
 	ch ar*  fo o;
 	foo  = "a";/ *Too l sh ould  det ect  this  lin e as  err or*/  /*E RROR :Sim ple  type  err or*/ 
	cout << *foo;
}
