/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.2
"using pointer to double,conditional statement if ~else using static variable of function scope"
*/
                     
static int staticflag1=1;   
void invalid_memory_access_002 ()
{
	double *ptr, *dptr = 0,a;
	static int staticflag=10;
    if (staticflag == 10)
    	  	(ptr= (double*) malloc(10*sizeof(double)));
    else
    	  	(dptr = (double*) malloc(5*sizeof(double)));

    if  (staticflag == 10 && ptr!=NULL)
    		(*(ptr+1) = 10.5);
    else
    	    (*(dptr+1) = 5.5) ;

    if(staticflag == 10 && ptr!=NULL)
    	a = *(ptr+1); /*Tool should not detect this line as error*/ /*No ERROR:Invalid memory access to already freed area*/
    else
    	a = *(dptr+1);

	printf("%lf",a);

    if(staticflag == 10 && ptr!=NULL)
    {
    	free(ptr);
    	ptr = NULL;
    }
    else
    {
    	free(dptr);
    	dptr = NULL;
    }
}
