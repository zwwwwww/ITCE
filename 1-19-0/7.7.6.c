/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.6
"using a pointer to char , and initialized in another function"
*/
   
void uninit_memory_access_006_func_001(char *dst, const char *src)
{
     if(src == NULL)
     {
         printf(""Null Assignment:\n"");
         return;
     }
     else
     {
    	 while(*src != '\0')
        {
    		 *dst = *src;
             src++;
             dst++;
        }
        *dst = '\0';
     }
 }
void uninit_memory_access_006 ()
{
    char *str1 = (char *) calloc(25,sizeof(char));
    char *str2 = ""STRING"";
    uninit_memory_access_006_func_001(str1, str2);
    printf(""%s\n"", str1);
}