/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.17
"return type function :int and typedef and function pointer: int *,void(int)"
*/
   
int (*wrong_arguments_func_pointer_017_func_gbl)(float flag2 ,int flag);     
int wrong_arguments_func_pointer_017_func_001 (int flag,float flag2)
{
	float a=0.0;
	a += flag2;
	flag = 1;
	return flag;
}

int wrong_arguments_func_pointer_017_func_002 (int flag,float flag2)
{
	int ret = 0;
	if (flag == 1)
	{
		goto my_label;
	}

	return ret;

my_label:
    if (flag == 1)
	{
    	wrong_arguments_func_pointer_017_func_gbl = (int (*)(float,int))wrong_arguments_func_pointer_017_func_001;
        goto my_label2;
 	ret ++;
	}

my_label2:
    if (flag == 1)
 	{
          flag = wrong_arguments_func_pointer_017_func_gbl(1.9,0);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
          flag2++;
 	}
	return ret;
}

void wrong_arguments_func_pointer_017 ()
{
    int flag;
    int (*fptr)(int,float);
    fptr =wrong_arguments_func_pointer_017_func_002;
    flag = fptr(1,4.5);
}