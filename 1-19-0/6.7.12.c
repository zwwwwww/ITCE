/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.12
"using a pointer to float , pointing to 1D array"
*/
             
void uninit_pointer_012 ()
{
	float * fptr =NULL;
	float arr[10];
	fptr = arr;
	int i;
	for(i=0; i<10; i++)
	{
		fptr[i] = (float)i;
	}
	for(i=0; i<10; i++)
	{
		arr[i] = ++fptr[i]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
	}
}
