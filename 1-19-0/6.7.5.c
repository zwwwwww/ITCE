/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.5
"pointer arrays	int	Function arguments	Loading"
*/
 
extern int sink;     
void uninit_pointer_005_func_001 (int *pbuf[])
{
	int buf1[6] = {1, 2, 3, 4, 5, 6};
	int buf2[6] = {1, 2, 3, 4, 5, 6};
	int buf3[6] = {1, 2, 3, 4, 5, 6};
	int buf4[6] = {1, 2, 3, 4, 5, 6};
	int buf5[6] = {1, 2, 3, 4, 5, 6};
	pbuf[0] = buf1;
	pbuf[1] = buf2;
	pbuf[2] = buf3;
	pbuf[3] = buf4;
	pbuf[4] = buf5;
	int ret;
	ret = pbuf[1][1];
        sink = ret;

}
void uninit_pointer_005 ()
{
	int *pbuf[5];
	uninit_pointer_005_func_001(pbuf); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}
