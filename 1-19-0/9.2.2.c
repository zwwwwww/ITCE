/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.2
"1-dimensional array	int	Constant	Write"
*/
                                                                                                     
extern int sink;                                                                                 
void underrun_st_002 ()
{
	int buf[5];
	buf[0] = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
        sink = buf[idx];
}