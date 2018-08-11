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
#include <sys/reg.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>



int	main(void)
{
	pid_t			child;

	child = fork();
	if (child == 0)
	{
		char * const args[] =  {NULL};

		ptrace(PTRACE_TRACEME, 0 , NULL, NULL);
		execve("./coucou", args, NULL);
	} 
	else 
	{
		int status;
		struct user_regs_struct regs;
		unsigned long int old;

		status = 0;
		old = 0;
		while (42)
		{
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
			waitpid(child, &status, 0);
			ptrace(PTRACE_GETREGS, child , NULL, &regs);
			if (old != regs.rip)
			{
				if ((int)regs.orig_rax == SYS_access)
					printf("access\n");
				else
					printf("not access\n");
				old = regs.rip;

			}
			if (WIFEXITED(status))
				break ;
		}
	}
	return (0);
}
