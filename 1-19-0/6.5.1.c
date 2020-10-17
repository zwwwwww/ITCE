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
    int buf1[10];
	int buf2[5];
	intptr_t offset;
	offset = buf1 - buf2; /*Tool should not detect this line as error*/ /*No ERROR:Incorrect pointer arithmetic*/
        sink = offset;
}