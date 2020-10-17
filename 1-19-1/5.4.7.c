/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.7
/struct
*/
   
typedef struct {
	int a;
	int b;
	int divisor;
} zero_division_007_s_001;

zero_division_007_s_001 zero_division_007_s_gbl;

void zero_division_007_func_001 ()
{
	zero_division_007_s_gbl.divisor = 0;
}

void zero_division_007 ()
{
	int dividend = 1000;
	int ret;
	zero_division_007_func_001();
	ret = dividend / zero_division_007_s_gbl.divisor;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}