/*
From:ITC
7
Resource management defects
7.1
Double free
7.1.1
"Basic type where pointer is ""freed""  twice"
*/
       
void double_free_001()
{
	char* ptr= (char*) malloc(sizeof(char));
	free(ptr);                        
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Double free*/
}