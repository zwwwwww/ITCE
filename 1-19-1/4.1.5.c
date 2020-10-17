/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.5
external variable type mistake
*/

extern char invalid_extern_001_glb_var5; /*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
void invalid_extern_005()
{
	invalid_extern_001_glb_var5 = 1.0;
}
