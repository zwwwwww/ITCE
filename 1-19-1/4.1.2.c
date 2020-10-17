/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.2
external variable type mistake
*/

extern int *invalid_extern_001_glb_float; /*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
void invalid_extern_002()
{
	invalid_extern_001_glb_float[3] = 1;
}
