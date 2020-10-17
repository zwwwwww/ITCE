/*
From:ITC
12
Input/Output defects
12.2
Fflush On Input Stream
12.2.1
Use fflush (stdin) to empty the input buffer
*/

int Fflush_on_input_stream_001() {
    int i, c;
    for (;;) {
        fputs("Please input an integer: ", stdout);
        if (scanf("%d", &i) != EOF) {
            while ((c = getchar()) != '\n' && c != EOF) {/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
                ;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}
