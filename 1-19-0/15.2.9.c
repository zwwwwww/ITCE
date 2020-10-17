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
volatile sig_atomic_t e_flag = 0;

void handler(int signum) {
	e_flag = 1;
}

int undefined_behavior_009(void) {
	char* err_msg = (char*)malloc(MAX_MSG_SIZE);
	if (err_msg == NULL) {
		/* Handle error */
	}

	signal(SIGINT, handler);
	strcpy(err_msg, "No errors yet.");
	/* Main code loop */
	if (e_flag) {
		strcpy(err_msg, "SIGINT received.");
	}
	return 0;
}
