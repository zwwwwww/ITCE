/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.8
Free in a function
*/
    
char *double_free_function_008_gbl_ptr;
void double_free_function_008()
{
	free (double_free_function_008_gbl_ptr);
}

void double_free_008()
{
	double_free_function_008_gbl_ptr= (char*) malloc(sizeof(char));

	double_free_function_008();
	free(double_free_function_008_gbl_ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}
