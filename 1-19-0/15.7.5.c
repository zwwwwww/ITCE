/*
From:ITC
15
Control flow defects
15.7
uncomplete logic
15.7.5
do-while logic is uncomplete
*/
                                                           
void uncomplete_logic_005() {
	int a = 0;
	do {
		a++;
	} while (a < 10);/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
}
