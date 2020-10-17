/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.7
The file was not closed
*/
                                                                                                          
 void operation_relate_to_file_007() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w");
	fputc("a", fp); /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}