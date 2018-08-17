/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:16:30 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/10 11:16:32 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"
#include <errno.h>

int	status;

void	wait_for_syscall(int child)
{
	sigset_t block;
	sigset_t empty;

	sigemptyset(&block);
	sigemptyset(&empty);
	ptrace(PTRACE_SYSCALL, child, NULL, NULL);
	waitpid(child, &status, 0);
	sigprocmask(SIG_SETMASK, &empty, NULL);
	sigaddset( &block, SIGINT );
	sigaddset( &block, SIGHUP );
	sigaddset( &block, SIGQUIT );
	sigaddset( &block, SIGPIPE );
	sigaddset( &block, SIGTERM );
	sigprocmask(SIG_BLOCK, &block, NULL);

}

int	is_print(char c)
{
	if (ft_isprint(c) || c == '\n')
		return (1);
	return (0);
}

int	is_printable(char *str)
{
	int i = -1;

	while (str && str[++i])
	{
		if  (!is_print(str[i]))
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

char  *trim_back(char *str)
{
	char *copy;
	char *temp;
	int i = -1;

	copy = ft_strdup(str);

	while (copy && copy[++i])
	{
		if (copy[i] == '\n')
		{
			temp = &copy[i + 1];
			copy[i] = 0;
			copy = ft_strjoin(copy, "\\n");
			copy = ft_strjoin(copy, temp);

		}
	}
	return (copy);

}

void 	get_data(int child, long reg, int flag)
{
	long res;
	char message[100000];
	char *temp;
	int i = -1;

	temp = message;
	res = 100;
	while (++i < 8)
	{
		res = ptrace(PTRACE_PEEKDATA, child, reg + i * 8, NULL);
		ft_memcpy(temp, &res, 8);
		temp += 8;
		//printf("\ntemp -> %ld\n", res);
	}

	if (flag)
		printf(", ");

	if (!errno)
		if (is_printable(message))
			printf("\"%s\"", trim_back(message));
		else
			printf("%p", message);
	else
		printf("%ld", reg);
}


void print_usage()
{
	printf("usage: ./ft_strace <PROG> args\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t			child;
	long rax;
	long rdi;
	long rsi;
	long rdx;
	long r10;
	long orig_rax;

	if (argc < 2)
		print_usage();
	child = fork();
	if (child == 0)
	{
		char * const args[] =  {NULL};
		execve(argv[1], args, NULL);
	} 
	else 
	{
		ptrace(PTRACE_SEIZE, child, 0, 0);
		ptrace(PTRACE_SYSCALL, child, 0, 0);
		ptrace(PTRACE_INTERRUPT, child, 0, 0);
		while (42)
		{
			wait_for_syscall(child);
			if (WIFEXITED(status))
				break ;
			else if (WIFSTOPPED(status))
			{
				if (WSTOPSIG(status) != SIGTRAP)
				{
					printf("--- %s---\n", get_signal_name(WSTOPSIG(status)));
					if (WSTOPSIG(status) == SIGSEGV)
						break;
					ptrace(PTRACE_INTERRUPT, child , 0, 0);
				}
			}
			rdi = ptrace(PTRACE_PEEKUSER, child, RDI * 8, NULL);
			rsi = ptrace(PTRACE_PEEKUSER, child, RSI * 8, NULL);
			rdx = ptrace(PTRACE_PEEKUSER, child, RDX * 8, NULL);
			r10 = ptrace(PTRACE_PEEKUSER, child, R10 * 8, NULL);
			orig_rax = ptrace(PTRACE_PEEKUSER, child, ORIG_RAX * 8, NULL);
			//	printf("rsi -> %ld old rsi -> %ld\n", rsi , old_rsi);
			if (orig_rax == SYS_clone)
				continue ;
			printf("%s(", get_syscall_name(orig_rax));
			if (orig_rax == SYS_exit_group)
			{
				(rdi) ? (get_data(child, rdi, 0)) : printf("0");
				printf(") = ?\n");
			}
			else
			{
				(rdi) ? (get_data(child, rdi, 0)) : printf("0");
				(rsi) ? (get_data(child, rsi, 1)) : 0;
				(rdx) ? (get_data(child, rdx, 1)) : 0;
				(r10) ? (get_data(child, r10, 1)) : 0;
				wait_for_syscall(child);
				rax = ptrace(PTRACE_PEEKUSER, child, RAX * 8, NULL);
				if (rax == -1)
					printf(") = ?\n");
				else if (rax < -1)
					printf(") = -1 %s\n", get_errno_name(rax));
				else
					printf(") = %ld\n", rax);
			}
		}
		if (WIFEXITED(status))
			printf("+++ exited with %d +++\n", WEXITSTATUS(status));
		else if (WIFSTOPPED(status))
		{
			printf("+++ killed by %s +++\n", get_signal_name(WSTOPSIG(status)));
			printf("%s\n", sys_siglist[WSTOPSIG(status)]);
		}
	}
	return (0);
}
