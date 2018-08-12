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

void	wait_for_syscall(int child, int *status){

	ptrace(PTRACE_SYSCALL, child, NULL, NULL);
	waitpid(child, status, 0);

}
char *get_text(int child, struct user_regs_struct regs)
{
	unsigned int i = -1;
	long res;
	char *temp = malloc(1000);
	char *temp2 = NULL;

	temp2 = temp;
	while (++i < regs.rdx )
	{
		res = ptrace(PTRACE_PEEKDATA, child, regs.rdi, NULL);
		ft_memcpy(temp2, &res, 8);
		temp2 += sizeof(long);
	}
	temp[regs.rdx] = 0;
	printf("temp -> %s", temp);
	return (temp);
	
}

int	main(void)
{
	pid_t			child;
	int status;

	status = 0;
	child = fork();
	if (child == 0)
	{
		char * const args[] =  {NULL};

		ptrace(PTRACE_TRACEME, 0 , NULL, NULL);
		execve("./coucou", args, NULL);
	} 
	else 
	{
		struct user_regs_struct regs;
		unsigned long int old;

		old = 0;
		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
		while (42)
		{
			wait_for_syscall(child , &status);
			ptrace(PTRACE_GETREGS, child , NULL, &regs);
			if (old != regs.rip)
			{
				printf("%s(", get_syscall_name(regs.orig_rax));
				(regs.rdi) ? (printf("%d,", (int)regs.rdi)) : 0;
				(regs.rsi) ? (printf("%d,", (int)regs.rsi)) : 0;
				(regs.rdx) ? (printf("%d,", (int)regs.rdx)) : 0;
				(regs.rcx) ? (printf("%d,", (int)regs.rcx)) : 0;
				printf(")\n");
				old = regs.rip;

			}
			if (WIFEXITED(status))
				break ;
		}
	}
	return (0);
}
