/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.18
function : structure pointer and function pointer :structure
*/

#define MAX 10
typedef struct {
    int arr[MAX];
    int a;
    int b;
    int c;
} wrong_arguments_func_pointer_018_s_001;

void (*wrong_arguments_func_pointer_018_fptr_gbl)(wrong_arguments_func_pointer_018_s_001*);

void (*wrong_arguments_func_pointer_018_fptr1_gbl)(wrong_arguments_func_pointer_018_s_001,wrong_arguments_func_pointer_018_s_001 *);
void (*wrong_arguments_func_pointer_018_fptr2_gbl)(wrong_arguments_func_pointer_018_s_001 *,int);
int func_pointer_018_global_set=0;                                                            void wrong_arguments_func_pointer_018_func_001(wrong_arguments_func_pointer_018_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
    func_pointer_018_global_set = 1;
}

void wrong_arguments_func_pointer_018_func_002(wrong_arguments_func_pointer_018_s_001 st,wrong_arguments_func_pointer_018_s_001* st1)
{
    int temp=0;
    int i;
    for (i = 0; i < MAX; i++)
    {
    	st.arr[i] = i;
    	st1->arr[i] = st.arr[i]+i;
    	temp += st.arr[i];
    }
}

void wrong_arguments_func_pointer_018_func_003(wrong_arguments_func_pointer_018_s_001 *st, int a)
{
    st->b = st->c+a;
}

void wrong_arguments_func_pointer_018_func_004(wrong_arguments_func_pointer_018_s_001 st,wrong_arguments_func_pointer_018_s_001* st1)
{
	if (func_pointer_018_global_set == MAX)
	{
		wrong_arguments_func_pointer_018_fptr1_gbl = wrong_arguments_func_pointer_018_func_002;
		wrong_arguments_func_pointer_018_fptr1_gbl(st,st1); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
	}
	else
	{
		wrong_arguments_func_pointer_018_fptr2_gbl = wrong_arguments_func_pointer_018_func_003;
		wrong_arguments_func_pointer_018_fptr2_gbl(&st,1);
	}
}

void wrong_arguments_func_pointer_018 ()
{
	wrong_arguments_func_pointer_018_s_001 st,*st1;
	st1 = (wrong_arguments_func_pointer_018_s_001 *)malloc(1*sizeof(wrong_arguments_func_pointer_018_s_001));
    memset(st1, 0, sizeof(*st1));

    wrong_arguments_func_pointer_018_fptr_gbl = wrong_arguments_func_pointer_018_func_001;
    wrong_arguments_func_pointer_018_fptr_gbl(&st);

	void (*fptr3)(wrong_arguments_func_pointer_018_s_001 st,wrong_arguments_func_pointer_018_s_001* st1);
	fptr3 = wrong_arguments_func_pointer_018_func_004;
	fptr3(st,st1);
}
