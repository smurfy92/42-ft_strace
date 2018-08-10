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

#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>



int	main(void)
{
	pid_t			child;
	unsigned long int	old;

	child = fork();
	if (child == 0)
	{
		char * const args[] =  {NULL};

		ptrace(PTRACE_TRACEME, 0 , NULL, NULL);
		execve("./coucou", args, NULL);
	} 
	else 
	{
		int		status;
		struct user_regs_struct	regs;
		long ins;

		old = 0;
		wait(&status);
		while (42)
		{
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			ins = ptrace(PTRACE_PEEKTEXT, child, regs.rip, NULL);

			if (old != regs.rip)
			{
				printf("rip : 0x%llx", regs.rip);
				printf("ins -> %lx\n", ins);
				//printf("rax -> %llu\n", regs.rax);
				//printf("rsp -> %llu\n", regs.rsp);
				//printf("rbp -> %llu\n", regs.rbp);
				//printf("rdi -> %llu\n", regs.rdi);
				old = regs.rip;
			}
			ptrace(PTRACE_SYSCALL, child , NULL, NULL);
			waitpid(child, &status, 0);
			if (WIFEXITED(status))
				break;
		}
	}
	return (0);
}
