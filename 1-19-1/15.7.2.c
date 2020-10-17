/*
From:ITC
15
Control flow defects
15.7
uncomplete logic
15.7.2
for logic is uncomplete
*/
                                                                                                              
void uncomplete_logic_002() {
	int i;
	for (i = 1; i < 10; i++) {
		/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
	}
}
