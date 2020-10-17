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
	ret = dividend / 1.0; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
