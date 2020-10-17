/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.6
Repositioning operation on a file opened in append mode
*/
                                                                                                                    
 void operation_relate_to_file_006() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w");
	rewind(fp); /*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fputc('a', fp);
	fclose(fp);
}