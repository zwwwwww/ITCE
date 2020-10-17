/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.4
"using a double pointer to float , memory allocated in an do - while loop"
*/
  
     
void free_null_pointer_004 ()
{
	float **fptr = (float**) malloc(5*sizeof(float*));
	int i=0,j=0;

do
{
	fptr[i]=NULL;
	i++;
}while (i<5);

    i=0;
    do
	{
		for(j=0;j<5;j++)
		{
			/**(*(fptr+i)+j)=i+0.5;*/
		}
	    free(fptr[i]); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	    i++;
    }while (i<5);
	free(fptr);
}