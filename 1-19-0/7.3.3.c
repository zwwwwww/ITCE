/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.3
 using a pointer to char in an infinite while loop and Strcpy
*/
             
void invalid_memory_access_003 ()
{
	int i=1;
	char *buf,*c = 0;
	while(i>0)
	{
		buf = (char *) malloc (25 * sizeof(char));
		if(buf!=NULL)
		{
			strcpy(buf,"This is String");
	        c = buf;
	        free(buf);
    	    buf = NULL; /*Tool should not detect this line as error*/ /*No ERROR:Invalid memory access to already freed area*/
		}
	    i++;
	    if(i>=10)
	    	break;
	}
        psink = c;
}
