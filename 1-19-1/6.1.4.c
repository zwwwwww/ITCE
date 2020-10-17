/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.4
return type function char * and function pointer: int 
*/
  
static char * func_pointer_004_func_001 (char *str1)
{
    int i = 0;
    int j;
    char * str_rev = NULL;
    if (str1 != NULL)
    {
        i = strlen(str1);
        str_rev = (char *) malloc(i+1);
        for (j = 0; j < i; j++)
        {
            str_rev[j] = str1[i-j-1];
        }
        str_rev[i] = '\0';
        return str_rev;
    }
    else
    {
        return NULL;
    }
}

void func_pointer_004 ()
{
    int j;
    char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        {
            char str;
            int (*fptr)(char *);
            fptr = (int (*)( char *))func_pointer_004_func_001;
            str = fptr(buf[j]);/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
        }
    }
}
