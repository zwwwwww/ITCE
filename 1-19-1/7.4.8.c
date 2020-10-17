/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.8
using a pointer to char in an infinite for loop
*/

#define MAX_VAL 10   
enum {max_buffer = MAX_VAL*2};
char * memory_allocation_failure_008_func_001 (const char *msg) {
  const char *error_log = msg;
  char * buffer = 0;
  int i;
  for(i=0;i<max_buffer;i++)
  {
	   buffer = (char*) malloc(max_buffer * sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
       break;
  }
  if(buffer!=NULL)
    snprintf(buffer, max_buffer * sizeof(char), ""Error: %s"", error_log);
  return buffer;
}
void memory_allocation_failure_008 ()
{
	char *str = "STRINGMEM";
	memory_allocation_failure_008_func_001(str);
}