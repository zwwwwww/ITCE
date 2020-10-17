/*
From:ITC
6
Pointer related defects
6.5
Incorrect pointer arithmetic
6.5.2
an incorrect pointer arithmetic
*/
       
extern int sink;    
void ptr_subtraction_002 ()
{
	int x= 10;
	int *ptr = &x;
	char *buf ;
	buf= (char *)(ptr+1); /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*/
}