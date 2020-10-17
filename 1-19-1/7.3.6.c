/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.6
using double pointers to the type float
*/
           
void invalid_memory_access_006 ()
{
	float *buf1=(float*)calloc(5,sizeof(float));
	float *buf2=(float*)calloc(5,sizeof(float));
	float *buf3=(float*)calloc(5,sizeof(float));
	float *buf4=(float*)calloc(5,sizeof(float));
	float *buf5=(float*)calloc(5,sizeof(float));
	float **pbuf[5] = {&buf1, &buf2, &buf3, &buf4, &buf5};
	int i,j=4;
	if(buf2 != NULL)
	{
	buf2[0] = 10.0;
	}
	for(i=0;i<5;i++)
	{
		*((*pbuf[i])+j)=5.0;
	}
	free(buf1);
	free(buf2);
	free(buf3);
	free(buf4);
	free(buf5);
	*((*pbuf[1])+1) =buf2[0]; /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}