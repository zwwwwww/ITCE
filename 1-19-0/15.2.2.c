/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.2
create a universal character name through concatenation
*/

#define assign(ucn, val) 
ucn = val
void undefined_behavior_002() {
	int \u0401;
	/* ... */
	assign(\u0401, 4);
	/* ... */
}
