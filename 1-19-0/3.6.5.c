/*
From:ITC
3
Inappropriate code
3.6
Unused variable
3.6.5
"basic types	static variable in the File"
*/

static int unused_var_005_glb_a = 1;
static int unused_var_005_glb_b = 2;
static int unused_var_005_glb_unuse;

void unused_var_005()
{
	unused_var_005_glb_unuse = unused_var_005_glb_a + unused_var_005_glb_b;
	printf(" % d ", unused_var_005_glb_unuse); /*Tool should not detect this line as error*/ /*No ERROR:Unused variable*/
}
