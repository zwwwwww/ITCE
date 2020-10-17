/*
From:ITC
12
Input/Output defects
12.3
IO Without Positioning
12.3.9
 redirect output without position
*/

void IO_without_009() {
	freopen("data.out", "w", stdout);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}