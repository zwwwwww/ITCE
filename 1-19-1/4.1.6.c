/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.6
external variable type mistake
*/

extern char *invalid_extern_001_glb_006_str; /*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/

void invalid_extern_006()
{
    invalid_extern_001_glb_006_str[1] = 'c';
}
