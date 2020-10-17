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
	     fptr[i]=(float*) malloc(5*sizeof(float));
	     i++;
    }while (i<5);

    i=0;
    do
	{
		for(j=0;j<5;j++)
		{
			*(*(fptr+i)+j)=i+0.5;/* Tool should not detect this line as error */ /*No ERROR:Freeing a NULL pointer*/
		}
	    free(fptr[i]);
	    i++;
    }while (i<5);
	free(fptr);
}
