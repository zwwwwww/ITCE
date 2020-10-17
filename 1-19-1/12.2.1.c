/*
From:ITC
12
Input/Output defects
12.2
Fflush On Input Stream
12.2.1
Use fflush (stdin) to empty the input buffer
*/
#include<stdio.h>
#include<stdlib.h>                                                                                                             
void Fflush_on_input_stream_001() {
		int i;
		for (;;) {
			fputs("Please input an integer: ", stdout);

			scanf("%d", &i);
			fflush(stdin);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
			printf("%d\n", i);
		}
		return 0;
	}
