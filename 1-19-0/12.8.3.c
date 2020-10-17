/*
From:ITC
12
Input/Output defects
12.8
Operation relate to file
12.8.3
File output without positioning results in undefined behaviour
*/
                                                                                                                               
void operation_relate_to_file_003() {
	FILE* fp;
	fp = (FILE*)fopen("x.txt", "w+");
	int a, b;
	fscanf(fp, "%d %d", &a, &b); /*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
	fclose(fp);
}