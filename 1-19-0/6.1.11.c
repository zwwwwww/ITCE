/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.11
double alias
*/
      
extern int sink;            
#define MAX 10
char * func_pointer_011_func_001 (const char *str1)
{
    int i = 0;
    int j;
    char * str_rev = NULL;
    if (str1 != NULL)
    {
        i = strlen(str1);

        str_rev = (char *) malloc(i+1);
        if(str_rev !=NULL)
        {
        	for (j = 0; j < i; j++)
            {
        		str_rev[j] = str1[j];
            }
            str_rev[j] = '\0';
        }
        return str_rev;
    }
    else
    {
        return NULL;
    }
}

void func_pointer_011 ()
{
    int j;
    const char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        if (MAX ==10)
    	{
            char * str;
            char *(*fptr)(const char *);
            char *(*fptr1)(const char *); 
            char *(*fptr2)(const char *);
            fptr = func_pointer_011_func_001;
            fptr1 = fptr;
            fptr2 = fptr1;
            str = fptr2(buf[j]);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
            psink = str;
        }
    }
 }
