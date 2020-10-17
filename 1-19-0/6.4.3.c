/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.3
" using a pointer to long in an infinite for loop , memory allocated and assigned inside a if condition"
*/

 
void free_null_pointer_003 ()
{
	int i;
	long *buf=NULL;
	for (i=0;;i++)
	{
		if(i>=10)
		break;
        buf=(long*) calloc(5,sizeof(long));
		if(buf!=NULL)
		{
			buf[0]=i;
		    free (buf);/* Tool should not detect this line as error */ /*No ERROR:Freeing a NULL pointer*/
		    buf = NULL;
		}
	}
}
