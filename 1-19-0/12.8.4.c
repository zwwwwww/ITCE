/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.4
Read to a file that has only been opened for writing
*/
                                                                                                                 
 void operation_relate_to_file_004() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "r");
	float fa[5];
	fread(fa, 4, 5, fp); /*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}