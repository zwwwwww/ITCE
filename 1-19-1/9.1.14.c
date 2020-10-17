/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.14
" 1-dimensional array	int	Value of random variable	Write"
*/
                                                                                  
extern int sink;                                                                                          
int rand(void);                                                                              
void overrun_st_014 ()
{
	int buf[5];
	int index;
	index = rand();
	buf[index] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx];
}
