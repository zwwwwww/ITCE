/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.10
"( signed) bitfield->	( signed) bit field"
*/
  
extern int sink;    
typedef struct {
	signed int ret : 5;
	signed int a : 7;
} data_lost_010_s_001;

void data_lost_010 ()
{
	data_lost_010_s_001 s;
	s.a = 0x0f;
	s.ret = s.a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
}
