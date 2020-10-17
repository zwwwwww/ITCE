/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.8
return type function void and function pointer: float** 
*/
      
extern int sink;              
static float a[2][3] = { {1.0,2.0,3.0},
		                {11.1,22.1,33.1} };
void func_pointer_008_func_001(float a[][3] , int max)
{
    a[max-1][2] = 50.6;
}

void func_pointer_008 ()
{
	switch(1)
	{
		case 1:
		{
			void (*fptr)(float [][3] , int); 
			fptr = func_pointer_008_func_001;
			fptr(a,1);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
			break;
		}
		default:
		{
			break;
		}
	}
}
