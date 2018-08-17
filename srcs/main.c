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

int	status;

int sigs()
{
	if (WIFEXITED(status))
		return (1);
	else if (WIFSTOPPED(status))
	{
		if (WSTOPSIG(status) != SIGTRAP)
		{
			printf("--- %s---\n", get_signal_name(WSTOPSIG(status)));
			if (WSTOPSIG(status) == SIGSEGV)
				return (1);
			ptrace(PTRACE_INTERRUPT, child , 0, 0);
		}
	}
	return (0);
}

void	get_sys_ret(int child)
{
	long rax;

	wait_for_syscall(child);
	rax = ptrace(PTRACE_PEEKUSER, child, RAX * 8, NULL);
	if (rax == -1)
		printf(") = ?\n");
	else if (rax < -1)
		printf(") = -1 %s\n", get_errno_name(rax));
	else
		printf(") = %ld\n", rax);
}

void get_regs(int child)
{
	long regs[6];

	regs[0] = ptrace(PTRACE_PEEKUSER, child, RDI * 8, NULL);
	regs[1] = ptrace(PTRACE_PEEKUSER, child, RSI * 8, NULL);
	regs[2] = ptrace(PTRACE_PEEKUSER, child, RDX * 8, NULL);
	regs[3] = ptrace(PTRACE_PEEKUSER, child, R10 * 8, NULL);
	regs[4] = ptrace(PTRACE_PEEKUSER, child, ORIG_RAX * 8, NULL);
	if (regs[4] == SYS_clone)
		return ;
	printf("%s(", get_syscall_name(regs[4]));
	if (regs[4] == SYS_exit_group)
	{
		(regs[0]) ? (get_data(child, regs[0], 0)) : printf("0");
		printf(") = ?\n");
	}
	else
	{
		(regs[0]) ? (get_data(child, regs[0], 0)) : printf("0");
		(regs[1]) ? (get_data(child, regs[1], 1)) : 0;
		(regs[2]) ? (get_data(child, regs[2], 1)) : 0;
		(regs[3]) ? (get_data(child, regs[3], 1)) : 0;
		get_sys_ret(child);
	}
}

void		process(int child)
{
	while (42)
	{
		wait_for_syscall(child);
		sigs();
		get_regs(child);
	}
}

int	main(int argc, char **argv)
{
	pid_t			child;
	

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
		process(child);
		get_ret();
	}
	return (0);
}
