/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.3
" 1-dimensional array	int	Variable	Write"
*/
                                                                                                   
extern int sink;                                                                                
void underrun_st_003 ()
{
	int buf[5];
	int index = 0;
	buf[index] = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
        sink = buf[idx];
}