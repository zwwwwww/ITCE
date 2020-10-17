/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.8
a decrement in a loop pointer value
*/
                                                                            
void underrun_st_008 ()
{
	int buf[5];
	int *p;
	int i;
	p = &buf[4];
	for (i = 0; i <= 5; i ++)
	{
		*p = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
		p --;
	}
}
