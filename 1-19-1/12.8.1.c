/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.1
Use a file that has been closed
*/
                                                                                                       
 void operation_relate_to_file_001() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "r");
	fclose(fp);
	float fa[5];
	fread(fa, 4, 5, fp); /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}