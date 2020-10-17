/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.3
using a char pointer and strcpy
*/
  
void uninit_memory_access_003 ()
{
	char *str1 = (char *) calloc(25,sizeof(char));
	char *str2 ;
	if (str1!=NULL)
	{
		strcpy(str1, str2);
        printf("%s %s\n",str1,str2);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
        free(str1);
	}
}