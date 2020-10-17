/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.2
create a universal character name through concatenation
*/

#define assign(uc1, uc2, val) 
uc1##uc2 = val

void undefined_behavior_002() {
	int \u0401;
	/* ... */
	assign(\u04, 01, 4);
	/* ... */
}
