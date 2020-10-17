/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.10
using a pointer to volatile structure in a do while loop and bit manipulations and global variable
*/
       
#define MAX_VAL 10           
#define ERROR   0x1
#define READY   0x2
#define RESET   0x4

#define NDEVS   4

void memory_allocation_failure_010_func_001(int devno)
{
	int i=0;
	if (devno <= NDEVS)
	{
	    do
	    {
		memory_allocation_failure_010_arr_gbl = (memory_allocation_failure_010_s_001 *) malloc (10*sizeof(memory_allocation_failure_010_s_001));
            i++;
	    }while( i<=MAX_VAL);
	}
}

void memory_allocation_failure_010_func_002(int devno)
{
    memory_allocation_failure_010_func_001(1);
    memory_allocation_failure_010_arr_gbl->csr = READY;
    do
    {
    	memory_allocation_failure_010_arr_gbl->data = READY;
        if(memory_allocation_failure_010_arr_gbl->csr & ERROR)
        {
        	memory_allocation_failure_010_arr_gbl->csr = RESET;
        }
    }while( (memory_allocation_failure_010_arr_gbl->csr & (READY | ERROR)) == 0);
}

void memory_allocation_failure_010 ()
{
	memory_allocation_failure_010_func_002(1);
	++memory_allocation_failure_010_arr_gbl->data;
}