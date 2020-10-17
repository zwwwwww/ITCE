/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.3
external variable type mistake
*/

extern int invalid_extern_001_glb_var3; /*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
void invalid_extern_003()
{
	invalid_extern_001_glb_var3 = 1;
}
