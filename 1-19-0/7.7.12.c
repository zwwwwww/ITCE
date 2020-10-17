/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.12
using structure padding and memcpy
*/
           
typedef struct {
int int_a;
short short_b;
short pad;
}uninit_memory_access_012_s_001;

void uninit_memory_access_012()
{
	uninit_memory_access_012_s_001  *s1, s;
    s1 = (uninit_memory_access_012_s_001*)calloc(1,sizeof(uninit_memory_access_012_s_001));
    if(s1 !=NULL)
    {
    	s1->int_a = 10;
        s1->short_b = 20;
        s1->pad = 20;
        memcpy(&s, s1, sizeof(uninit_memory_access_012_s_001)); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Memory Access*/
        free(s1);
    }
}