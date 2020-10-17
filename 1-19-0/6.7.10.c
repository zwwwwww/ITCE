/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.10
 void pointer to data passed from one function to another
*/
      
extern int sink;           
void uninit_pointer_010_func_001 (void * vptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * cptr = (char * *)vptr;
    char * buf = ""String"";
    buf = (*cptr); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
    sink = buf[idx];
}
void uninit_pointer_010 ()
{
    void *buf1;
	buf1 = ""String Test"";
    uninit_pointer_010_func_001(&buf1);    
}
