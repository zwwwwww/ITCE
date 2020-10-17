/*
From:ITC
8
Stack related defects 
8.2
Stack over?ow
8.2.1
large internal variables
*/


extern int sink;

void st_overflow_001()
{
	double buf[1048576]; /* 1MB bytes */ /*Tool should detect this line as error*/ /*ERROR:Stack overflow*/
	buf[0] = 1.0;
	sink = buf[idx];
}
"
