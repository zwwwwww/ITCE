/*
From:ITC
6
Pointer related defects
6.5
Incorrect pointer arithmetic
6.5.1
an incorrect pointer arithmetic
*/
    
extern int sink;        
void ptr_subtraction_001 ()
{
	char buf1[5];
	char buf2[5];
	intptr_t offset;
	offset = buf2 - buf1; /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*/
        sink = offset;
}