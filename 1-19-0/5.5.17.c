/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.17
" a short	int->An array of element values"
*/
      
extern int sink;         
void data_lost_017 ()
{
	short ret;
	int buf[5] = {0x8111, 0x8001, 0x8011, 0x7fff, 0x8111};
	ret = buf[3];/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
