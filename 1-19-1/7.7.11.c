/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.11
using a pointer to constant  char and snprintf
*/
         
enum {max_buffer = 24};

void uninit_memory_access_011_func_001 (const char *msg) {
  const char *error_log = msg;
  char buffer[max_buffer];

  snprintf(buffer, sizeof(buffer), "Error: %s", error_log);
  printf(" test %s\n", buffer);
}
void uninit_memory_access_011 ()
{
	char *str ;
	uninit_memory_access_011_func_001(str);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
}