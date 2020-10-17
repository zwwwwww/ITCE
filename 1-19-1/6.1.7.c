/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.7
return type function int and function pointer: char** 
*/
  
int func_pointer_007_func_001(char a[])
{
    int i=0;
	return (a[i]);
}

void func_pointer_007 ()
{
 	char buf[10] = "A string";
	char ** (*fptr)(char []);
	char ** a = NULL;
	fptr = (char ** (*)(char []))func_pointer_007_func_001;
	a =fptr(buf);/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
}
