/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.7
 Structure passed as function parameter and initialized partially in another function using mem set
*/
  
#define MAX 10
typedef struct {
    int arr[MAX];
    int a;
    int b;
    int c;
} uninit_memory_access_007_s_001;

void uninit_memory_access_007_func_001(uninit_memory_access_007_s_001* st)
{
    memset(st, 0, sizeof(*st));
    /* memset(st->arr, 0, sizeof(st->arr[0]) * (MAX-1));*/
    st->a = 1;
}
void uninit_memory_access_007_func_002(uninit_memory_access_007_s_001 *st)
{
    int temp=0;
    int i;
    for (i = 0; i < MAX; i++)
    {
        temp += st->arr[i];
    }
}

void uninit_memory_access_007_func_003(uninit_memory_access_007_s_001 *st)
{
    st->b = 10;
	st->c =20;
}

void uninit_memory_access_007_func_004(int num)
{
  int temp = 0;
    if(num != 0) {
        temp = num;
    }
    sink = temp;
}
void uninit_memory_access_007 ()
{
	uninit_memory_access_007_s_001 st;
	uninit_memory_access_007_func_001(&st);
	uninit_memory_access_007_func_002(&st);
	uninit_memory_access_007_func_003(&st);
	uninit_memory_access_007_func_004(st.a);
}
