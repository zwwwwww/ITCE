/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.8
using 1 single char pointer  memcpy function
*/
     
void invalid_memory_access_008 ()
{
	char* buf=(char*) calloc(25, sizeof(char));
	char* buf1= "This is a string";
	if(buf != NULL)
	{
		memcpy(buf,buf1,11); /*Tool should not detect this line as error*/ /*No ERROR:Invalid memory access to already freed area*/
	    free(buf);
	    buf = NULL;
	}
}
