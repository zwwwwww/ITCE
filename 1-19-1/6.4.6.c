/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.6
"using a pointer to structure ,memory allocated based on function return value"
*/
        
#inlude<string.h>           
int free_null_pointer_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

typedef struct {
	int a;
	int b;
	char *buf;
} free_null_pointer_006_s_001;

void free_null_pointer_006 ()
{
	int flag=0,i;
	char *s1="This is a string";
	free_null_pointer_006_s_001* s=(free_null_pointer_006_s_001*) calloc(5,sizeof(free_null_pointer_006_s_001)) ;

	if(free_null_pointer_006_func_001(flag)==0)
	{
		for(i= 0; i<5 ;i++)
	    {
			(s+i)->buf = NULL;
	    }
	    strcpy((s+4)->buf,s1);
	}
	if(free_null_pointer_006_func_001(flag)==0)
	{
		for(i= 0; i<5 ;i++)
			free((s+i)->buf);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	}
	free(s);
}