#include "../includes/ft_strace.h"

char *get_signal_name(int key)
{
	switch (key){
		case (SIGSEGV):
			return "SIGSEGV";
		default:
			return "unknown signal";
	}
}
