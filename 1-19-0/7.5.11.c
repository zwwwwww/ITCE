/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.11
using alias(union) - a union containing two methods of accessing the same data (within the same function) alias
*/
                 
typedef union {
    char * u1;
    char * u2;
} memory_leak_0011_uni_001;


void memory_leak_0011()
{
    char * buf = NULL;
    memory_leak_0011_uni_001 un;
    buf = (char *)calloc(50, sizeof(char)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	if(buf!=NULL)
	{
          strcpy(buf, "This Is A String");
          un.u1 = buf;
          char * buf = un.u1;
          if (buf)
            free(buf);
          buf = NULL;
        }
}