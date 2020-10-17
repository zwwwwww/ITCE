/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.3
external variable type mistake
*/

extern float invalid_extern_001_glb_var3[5];
void invalid_extern_003()
{
	invalid_extern_001_glb_var3[3] = 1.0;
}
