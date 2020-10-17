/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.12
"Warn on uses of the ¡®rand¡¯, ¡®random¡¯, and related functions"
*/
void invalid_function_arg_012() {
	random(); /*Tool should detect this line as eror*/ /*ERROR: API error*/
}
