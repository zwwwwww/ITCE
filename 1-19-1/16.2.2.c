/*
From:ITC
16
Macros defects
16.2
Side effect free parameters
16.2.2
assert() macro containing an expression (index++) that has a side effect
*/
                                                                
void side_effect_free_parameters_002(size_t index) {
	assert(index++ > 0); /* Side effect */ /*Tool should detect this line as error*/ /*ERROR:Macros error*/
	
}
