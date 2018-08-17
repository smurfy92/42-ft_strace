#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "../libft/includes/libft.h"


char *get_errno_name(int key);
char *get_syscall_name(int key);
char *get_signal_name(int key);
int	is_print(char c);
int	is_printable(char *str);
char  *trim_back(char *str);
void print_usage();
void	wait_for_syscall(int child);
void	get_ret();
void 	get_data(int child, long reg, int flag);
