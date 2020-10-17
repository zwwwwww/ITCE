/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.8
"using a double pointer to char , and initialized in another function"
*/
                   
#inlude<string.h>                        
enum {min_buffer = 0 , max_buffer = 5 };
static unsigned int min=min_buffer+2;
static unsigned int max=max_buffer+2;
void free_null_pointer_008_func_001 (int len,char **stringPtr)
{
	char * p = NULL;
	if(min <= min_buffer && max <= max_buffer)
    {
		p = malloc(sizeof(char) * (len+1));
	    *stringPtr = p;
    }
}

void free_null_pointer_008 ()
{
	char *str = "This is a string";
	char *str1=NULL;
	free_null_pointer_008_func_001(strlen(str),&str1);
	strcpy(str1,str);
	free(str1);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	str1 = NULL;
}