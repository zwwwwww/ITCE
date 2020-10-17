/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.3
Bad string constant format
*/
                                                                                                       
#define Name Jackson
void constant_macros_003(){
	printf("%s", Name); /*Tool should detect this line as error*/ /*ERROR:Macros error*/
}
