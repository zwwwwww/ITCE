/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.10
using a double pointer to char in an infinite while loop
*/
                    
#inlude<string.h>                       
char **free_null_pointer_010_gbl_dst=NULL;             
#define SET_MEM 0
void free_null_pointer_010_func_001()
{
	int i;
    {
		while(SET_MEM)
		{
			free_null_pointer_010_gbl_dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	free_null_pointer_010_gbl_dst[i]=(char*) malloc(15*sizeof(char));
		    }
		    break;
		}
    }
}
void free_null_pointer_010_func_002(char **dst, char (*src)[15])
{
	int i;
	for(i=0;i<5;i++)
	{
	   strcpy(*(dst+i),src[i]);
	}
}
void free_null_pointer_010_func_003()
{
	int i;
	while(SET_MEM)
	{
		for(i=0;i<5;i++)
	    {
			free(free_null_pointer_010_gbl_dst[i]);
			free_null_pointer_010_gbl_dst[i] = NULL;
	    }
	    break;
	}
	while(SET_MEM == 0)
	{
	    free(free_null_pointer_010_gbl_dst);
	    free_null_pointer_010_gbl_dst = NULL;/*ERROR:Freeing a NULL pointer*/
	    break;
	}
}
void free_null_pointer_010 ()
{
    char str2[][15] = {{"STRING"},
    		       {"TEST"},{"STRING#"},{"TEST!"},{"TRIAL"}};
    free_null_pointer_010_func_001();
    free_null_pointer_010_func_002(free_null_pointer_010_gbl_dst,str2);
    free_null_pointer_010_func_003();
}