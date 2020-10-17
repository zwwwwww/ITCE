/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.12
function : structure pointer and function pointer :structure
*/
     
#define MAX 10
typedef struct {
    int arr[MAX];
    int a;
    int b;
    int c;
} wrong_arguments_func_pointer_012_s_001;

void wrong_arguments_func_pointer_012_func_001(wrong_arguments_func_pointer_012_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
}

void wrong_arguments_func_pointer_012_func_002(wrong_arguments_func_pointer_012_s_001 st,wrong_arguments_func_pointer_012_s_001* st1)
{
    int temp=0;
    int i;
    memset(st1, 0, sizeof(*st1));
    for (i = 0; i < MAX; i++)
    {
    	st.arr[i] = i;
    	st1->arr[i] = st.arr[i]+i;
    	temp += st.arr[i];
    }
}

void wrong_arguments_func_pointer_012_func_003(wrong_arguments_func_pointer_012_s_001 *st, int a)
{
    st->b = st->c+a;
}

void wrong_arguments_func_pointer_012 ()
{
	wrong_arguments_func_pointer_012_s_001 st,*st1;
	st1 = (wrong_arguments_func_pointer_012_s_001 *)malloc(1*sizeof(wrong_arguments_func_pointer_012_s_001));

	void (*fptr)(wrong_arguments_func_pointer_012_s_001*);
	fptr = wrong_arguments_func_pointer_012_func_001;
	fptr(&st); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/

	void (*fptr1)(wrong_arguments_func_pointer_012_s_001,wrong_arguments_func_pointer_012_s_001 *);
	fptr1 = wrong_arguments_func_pointer_012_func_002;
	fptr1(st,st1);

	void (*fptr2)(wrong_arguments_func_pointer_012_s_001 *,int);
	fptr2 = wrong_arguments_func_pointer_012_func_003;
	fptr2(&st,1);
}
