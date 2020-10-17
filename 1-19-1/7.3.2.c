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
	static int staticflag=100;
    if (staticflag == 10)
    	  	(ptr= (double*) malloc(10*sizeof(double)));
    else
    	  	(dptr = (double*) malloc(5*sizeof(double)));

    if  (staticflag == 10 && ptr!=NULL)
    		(*(ptr+1) = 10.5);
    else
    	    (*(dptr+1) = 5.5) ;

    if(staticflag == 10 && ptr!=NULL)

    {
    	free(ptr);
    }
    else
    {
    	free(dptr);
    }

    if(staticflag == 10)
    {
	    ;
	}
    else
    	a = *(dptr+1);/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
	printf("%lf",a);
}