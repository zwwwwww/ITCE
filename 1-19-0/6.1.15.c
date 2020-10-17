/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.15
function : returns void and function pointer :structure
*/
     
extern int sink;            
void func_pointer_015_func_001(func_pointer_015_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
    global_set = 1;
}

void func_pointer_015_func_002(func_pointer_015_s_001* st1)
{
    int temp=0;
    int i;
    for (i = 0; i < MAX; i++)
    {
    	st1->arr[i] += i;
    	temp += st1->arr[i];
    }
}

void func_pointer_015_func_003(func_pointer_015_s_001 *st)
{
    st->b = st->c;
}

void func_pointer_015_func_004(func_pointer_015_s_001* st1)
{
	if (global_set == MAX)
	{
	   fptr1_gbl = func_pointer_015_func_002;
	   fptr1_gbl(st1);
	}
	else
	{
		fptr2_gbl = func_pointer_015_func_003; 
		fptr2_gbl(st1);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
}

void func_pointer_015 ()
{
	func_pointer_015_s_001 st,*st1;
	st1 = (func_pointer_015_s_001 *)malloc(1*sizeof(func_pointer_015_s_001));
    memset(st1, 0, sizeof(*st1));

	fptr_gbl = func_pointer_015_func_001;
	fptr_gbl(&st);

	void (*fptr3)(func_pointer_015_s_001* st1);
	fptr3 = func_pointer_015_func_004;
	fptr3(st1);
}
