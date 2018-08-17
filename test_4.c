#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void null_handler(int sig) { }

int main(int argc, char *argv[]) {
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGCHLD);
	sigaddset(&set, 33);
	sigaddset(&set, 35);
	sigaddset(&set, 63);
	sigaddset(&set, 64);
	sigprocmask(SIG_BLOCK, &set, NULL);
	signal(SIGINT, null_handler);
	raise(SIGINT);
	write(1, "toto\n", 5);
	return 0;
}
