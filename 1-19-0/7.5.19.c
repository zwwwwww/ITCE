/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.19
file opened and not closed
*/
(void) file_opened_and_not_closed {
    FILE *fp;
    fp=fopen("c:\\test.txt", "r"); 
    fclose(fp);
}
