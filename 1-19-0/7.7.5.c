/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.5
Float 3D array partially initialized from another 3D array
*/
             
void uninit_memory_access_005 ()
{
    int i,j,k;
	int arr[2][3][4] = { { {1, 2, 3, 4}, {12, 22, 32, 42}, {13, 23, 33, 43} },
                          { {21, 22, 23, 24}, {31, 32, 33, 34}, {41, 42, 43, 44} } };
	int arr1[2][3][4];
	for(i=0;i<2;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<4;k++)
				{
                    arr1[i][j][k] = arr[i][j][k];
					}
			}
		}
	k = arr1[1][2][3]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Memory Access*/
}