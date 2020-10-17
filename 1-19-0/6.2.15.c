/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.15
"function : double pointer to char , pointer to char array and function pointer :double pointer to char"
*/
             
char **wrong_arguments_func_pointer_015_dst1_gbl=NULL;  
void wrong_arguments_func_pointer_015_func_002(char **wrong_arguments_func_pointer_015_dst1_gbl, char (*src)[15])
{
	int i;
	for(i=0;i<5;i++)
	{
	   strcpy(*(wrong_arguments_func_pointer_015_dst1_gbl+i),src[i]);
	}
}

void wrong_arguments_func_pointer_015 ()
{
    char str2[][15] = {{""STRING""},
    		       {""TEST""},{""STRING#""},{""TEST!""},{""TRIAL""}};
	int i;
	wrong_arguments_func_pointer_015_dst1_gbl = (char**) malloc(5*sizeof(char*));
    for(i=0;i<5;i++)
    {
    	wrong_arguments_func_pointer_015_dst1_gbl[i]=(char*) malloc(15*sizeof(char));
    }
	while(1)
	{
		void (*fptr)(char **,char (*)[]);
	    fptr = wrong_arguments_func_pointer_015_func_002;
	    fptr(wrong_arguments_func_pointer_015_dst1_gbl,str2); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
	    break;
	}
	for(i=0;i<5;i++)
    {
		free(wrong_arguments_func_pointer_015_dst1_gbl[i]);
        wrong_arguments_func_pointer_015_dst1_gbl[i] = NULL;
    }
    free(wrong_arguments_func_pointer_015_dst1_gbl);
    wrong_arguments_func_pointer_015_dst1_gbl = NULL;
}
