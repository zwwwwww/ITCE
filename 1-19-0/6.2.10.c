/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.10
function : structure pointer and function pointer :structure
*/
              
typedef struct {
    int a;
    int b;
} wrong_arguments_func_pointer_010_s_001;

void wrong_arguments_func_pointer_010_func_001(wrong_arguments_func_pointer_010_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
    st->b=2;
}

void wrong_arguments_func_pointer_010 ()
{
 	wrong_arguments_func_pointer_010_s_001 st;
	void (*fptr)(wrong_arguments_func_pointer_010_s_001*);
	fptr = wrong_arguments_func_pointer_010_func_001;
	fptr(&st); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
