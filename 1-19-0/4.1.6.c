/*
From:ITC
4
Misc defects
4.1
Bad extern type for global variable 
4.1.6
external variable type mistake
*/

typedef struct
{
        int csr;
        int data;
} invalid_extern_001_glb_006_s_001;

extern invalid_extern_001_glb_006_s_001 *invalid_extern_001_glb_006_str;
void invalid_extern_006()
{
        invalid_extern_001_glb_006_str = (invalid_extern_001_glb_006_s_001 *)malloc(1 * sizeof(invalid_extern_001_glb_006_s_001));
        invalid_extern_001_glb_006_str->csr = 10;
}
