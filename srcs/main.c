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

void	wait_for_syscall(int child, int *status){

	ptrace(PTRACE_SYSCALL, child, NULL, NULL);
	waitpid(child, status, 0);

}

void 	get_data(int child, long reg, int flag)
{
	long res;
	char message[1000];
	char *temp;
	int i = -1;

	temp = message;
	while (++i < 4)
	{
		res = ptrace(PTRACE_PEEKDATA, child, reg + i * 8, NULL);
		ft_memcpy(temp, &res, 8);
		temp += 8;
	}

	message[temp - message -1 ] = 0;
	if (flag)
		printf(", ");
	if (!errno)
		printf("\"%s\"", message);
	else
		printf("%ld", reg);
}


int	main(void)
{
	pid_t			child;
	int status;
	int flag;

	flag = 0;
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
		struct user* user_space = (struct user*)0;

		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
		while (42)
		{
			long rax;
			long rdi;
			long rsi;
			long rdx;
			long r10;
			wait_for_syscall(child , &status);
			ptrace(PTRACE_GETREGS, child , NULL, &regs);
			if (flag == 0)
			{
				flag = 1;
			//	printf("rsi -> %ld old rsi -> %ld\n", rsi , old_rsi);
				rax = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rax, NULL);
				printf("%s(", get_syscall_name(regs.orig_rax));
				rdi = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rdi, NULL);
				(rdi) ? (get_data(child, rdi, 0)) : printf("0");
				rsi = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rsi, NULL);
				(rsi) ? (get_data(child, rsi, 1)) : 0;
				rdx = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rdx, NULL);
				(rdx) ? (get_data(child, rdx, 1)) : 0;
				r10 = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.r10, NULL);
				(r10) ? (get_data(child, r10, 1)) : 0;
				printf(") => %ld\n", rax);
			}
			else
			{
				flag = 0;
			}
			if (WIFEXITED(status))
				break ;
		}
	}
	return (0);
}
