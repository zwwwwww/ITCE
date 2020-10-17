/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.14
"function : long array, int and function pointer :float pointer"
*/
       
int wrong_arguments_func_pointer_014_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

long wrong_arguments_func_pointer_014_func_002 (long a[],int max)
{
	int i;
	for(i=0;i<max;i++)
	{
		a[i] = i;
	}
	return a[i];
}

void wrong_arguments_func_pointer_014 ()
{
	float f;
	f=0.7;
	if(wrong_arguments_func_pointer_014_func_001(0) == 0)
	{
		long (*fptr)(float *);
		long a;
		fptr = (long (*)(float * ))wrong_arguments_func_pointer_014_func_002;
		a =fptr(&f);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
	}

}