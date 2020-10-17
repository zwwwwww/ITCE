/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.8
/float
*/
    
void zero_division_008 ()
{
	float dividend = 1000.0;
	float ret;
	ret = dividend / 0.0;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}