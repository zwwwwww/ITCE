/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.4
external variable type mistake
*/

extern int invalid_extern_001_glb_var4;
void invalid_extern_004()
{
	invalid_extern_001_glb_var4 = 1;
}
