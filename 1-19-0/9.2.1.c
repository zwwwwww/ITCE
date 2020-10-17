/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.1
" 1-dimensional array	int	Constant	Loading"
*/
                                                                                                    
extern int sink;                                                                                 
void underrun_st_001 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int ret;
	ret = buf[0]; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
        sink = ret;
}