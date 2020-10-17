/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.11
"struct array	-	Constant	Write"
*/
                                                                                
extern int sink;                                                                                       
typedef struct {
	int a;
	int b;
	int c;
} overrun_st_011_s_001;

void overrun_st_011 ()
{
	overrun_st_011_s_001 sbuf[5];
	sbuf[5].a = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
}
