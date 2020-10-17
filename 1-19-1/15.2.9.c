/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.9
access shared objects in signal handlers
*/


enum { MAX_MSG_SIZE = 24 };
char* err_msg;

void handler(int signum) {
	strcpy(err_msg, "SIGINT encountered.");
}

int undefined_behavior_009() {
	signal(SIGINT, handler);

	err_msg = (char*)malloc(MAX_MSG_SIZE);
	if (err_msg == NULL) {
		/* Handle error */
	}
	strcpy(err_msg, "No errors yet.");
	/* Main code loop */
	return 0;
}
