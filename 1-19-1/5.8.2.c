/*
From:ITC
5
Numerical defects
5.8
Integer Overflow or Wraparound
5.8.2
"short int primitive type has a maximum value of 32768, which creates a potential integer overflow"
*/
#define JAN 1
#define FEB 2
#define MAR 3

short getMonthlySales(int month) {...}
float calculateRevenueForQuarter(short quarterSold) {...}
int integer_overflow002() {
// Variable for sales revenue for the quarter
float quarterRevenue = 0.0f;

short JanSold = getMonthlySales(JAN); /* Get sales in January */
short FebSold = getMonthlySales(FEB); /* Get sales in February */
short MarSold = getMonthlySales(MAR); /* Get sales in March */

// Calculate quarterly total
short quarterSold = JanSold + FebSold + MarSold;

// Calculate the total revenue for the quarter
quarterRevenue = calculateRevenueForQuarter(quarterSold);
saveFirstQuarterRevenue(quarterRevenue);

return 0;
}
