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
    int i=0;
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
	st.a = 10;
	char *i=""STRING BUFFER"";
	void (*fptr)(char*);
	fptr = (void (*)(char*))wrong_arguments_func_pointer_011_func_001;
	fptr(i);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
	void (*fptr1)(wrong_arguments_func_pointer_011_s_001*);
	fptr1 = wrong_arguments_func_pointer_011_func_002;
	fptr1(&st);
	fptr1 = wrong_arguments_func_pointer_011_func_003;
	fptr1(&st);

}
