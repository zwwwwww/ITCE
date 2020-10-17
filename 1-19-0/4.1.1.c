/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.1
external variable type mistake
*/

extern int invalid_extern_001_glb_buf[5];
void invalid_extern_001()
{
	invalid_extern_001_glb_buf[3] = 1;
}
