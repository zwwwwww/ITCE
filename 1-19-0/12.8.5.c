/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.5
 Write to a file that has only been opened for reading
*/
                                                                                                                            
 void operation_relate_to_file_005() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w");
	char c = 'a';
	fputc(c, fp); /*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}