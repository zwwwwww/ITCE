/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.5
Array of pointers
*/
                         
void free_nondynamic_allocated_memory_005()
{
	char *buf1=(char*)calloc(5,sizeof(char));
	char *buf2=(char*)calloc(5,sizeof(char));
	char **pbuf[2] = {&buf1, &buf2};
	int i,j=1;
	if(buf2 != NULL)
	{
	    buf2[0] = 10.0;
	}
	for(i=0;i<2;i++)
	{
		*((*pbuf[i])+j)=5.0;
	}
	free(buf1);
	free(buf2); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
