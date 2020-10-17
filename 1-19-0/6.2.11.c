/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.11
function : structure pointer and function pointer :structure
*/
       
#define MAX 10
typedef struct {
    int arr[MAX];
    int a;
    int b;
    int c;
} wrong_arguments_func_pointer_011_s_001;

void wrong_arguments_func_pointer_011_func_001(wrong_arguments_func_pointer_011_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
}

void wrong_arguments_func_pointer_011_func_002(wrong_arguments_func_pointer_011_s_001 *st)
{
    int temp;
    int i;
    for (i = 0; i < MAX; i++)
    {
    	st->arr[i] = i;
    	temp = st->arr[i];
    }
}

void wrong_arguments_func_pointer_011_func_003(wrong_arguments_func_pointer_011_s_001 *st)
{
    st->b = st->c;
}

void wrong_arguments_func_pointer_011 ()
{
 	wrong_arguments_func_pointer_011_s_001 st;
	void (*fptr)(wrong_arguments_func_pointer_011_s_001*);
	fptr = wrong_arguments_func_pointer_011_func_001; /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
	fptr(&st);
	fptr = wrong_arguments_func_pointer_011_func_002;
	fptr(&st);
	fptr = wrong_arguments_func_pointer_011_func_003;
	fptr(&st);
}
