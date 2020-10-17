/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.8
"using a pointer to ( signed) bit field variable ,initialized by return value of function"
*/
             
typedef struct {
	signed int a : 7;
	signed int b : 7;
} uninit_memory_access_008_s_001;

uninit_memory_access_008_s_001 * uninit_memory_access_008_func_001()
{
	uninit_memory_access_008_s_001 *ret = (uninit_memory_access_008_s_001 *) malloc (5*sizeof(uninit_memory_access_008_s_001));
	if (ret!=NULL)
	{
		ret->a = 0x0f;
		ret->b = 0x0f;
	}
	return ret;
}

void uninit_memory_access_008 ()
{
	uninit_memory_access_008_s_001 *s = NULL;
	s = uninit_memory_access_008_func_001();
	if(s!=NULL)
	{
		s->b = (s->a)+10; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Memory Access*/
		free (s);
	}
}
