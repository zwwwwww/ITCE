/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.1
" 1-dimensional array	int	Constant	Loading"
*/
                                                                                
void underrun_st_001 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int ret;
	ret = buf[-1];/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
}
