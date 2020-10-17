/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.11
 using a pointer to union in an switch case and random function and static pointer to union
*/
                    
#inlude<string.h>                         
int rand(void);                          
typedef union {
	int a;
	int b;
} free_null_pointer_011_u_001;

static free_null_pointer_011_u_001 *u;
free_null_pointer_011_u_001 * free_null_pointer_011_func_001 ()
{

	int flag = 0;
	switch (flag)
	{
		case 1:
		{
			u = (free_null_pointer_011_u_001 *)calloc(1,sizeof(free_null_pointer_011_u_001));
			u->a = 40;
			return u;
		}
		case 2:
		{
			u = (free_null_pointer_011_u_001 *)calloc(2,sizeof(free_null_pointer_011_u_001));
			u->a = 20;
			return u;
		}
		case 3:
		{
			u = (free_null_pointer_011_u_001 *)calloc(3,sizeof(free_null_pointer_011_u_001));
			u->a = 30;
			return u;
		}
		default:
			return (free_null_pointer_011_u_001 *)(-1);
	}
}

free_null_pointer_011_u_001 * free_null_pointer_011_func_002 ()
{
	int flag = rand();
	switch (flag)
	{
		case 1:
		{
			free(u); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
			u= NULL;
			return u;
		}
		case 2:
		{
			return u;
		}
		case 3:
		{
			return u;
		}
		default:
			return (free_null_pointer_011_u_001 *)(-1);
	}
}

void free_null_pointer_011 ()
{
	int ret;
	free_null_pointer_011_u_001 *p;
	p = free_null_pointer_011_func_001 ();
	ret = p->b;
	p = free_null_pointer_011_func_002 ();
}