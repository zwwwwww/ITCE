/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.7
i2 and i5 are defined as having both internal and external linkage
*/
                                                                                                                            
int i1 = 10;
static int i2 = 20;
extern int i3 = 30;
static int i5;
void initialization_007() {
	int i4 = i1 + i2;/*Tool should Not detect this line as error*/ /*ERROR:initialization error*/
	printf("%d", i4);
}
