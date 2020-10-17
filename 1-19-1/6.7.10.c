/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.10
 void pointer to data passed from one function to another
*/
   
void uninit_pointer_010_func_001 (void * vptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * cptr = (char * *)vptr;
    char * buf ;
    buf = (*cptr);/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}
void uninit_pointer_010 ()
{
    void *buf1;
    uninit_pointer_010_func_001(&buf1);
}
