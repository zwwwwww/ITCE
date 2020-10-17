/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.5
external variable type mistake
*/

extern float invalid_extern_001_glb_var5;
void invalid_extern_005()
{
	invalid_extern_001_glb_var5 = 1.0;
}
