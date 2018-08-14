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
void get_text(int child)
{
	long res;

	res = ptrace(PTRACE_PEEKUSER, child, 8 * RSI, NULL);
	
	if (errno)
		printf("errno set");
	printf(" res -> %ld\n", res);
}

int validate_hex(const char* hex)
{
  while(*hex != 0){
    if(*hex < '0' || *hex > '9')
      return 0;
    if(*hex < 'A' || *hex > 'F')
      return 0;
    hex++;
  }
  return 1;
}

void  print_reg(long t)
{
	if (validate_hex((char *)t))
		printf(", %p", (void *)t);
	else
		printf(", %ld", t);
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
			rax = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rax, NULL);
			rdi = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rdi, NULL);
			rsi = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rsi, NULL);
			rdx = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rdx, NULL);
			r10 = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.r10, NULL);
			if (flag == 0)
			{
				flag = 1;
				printf("%s(", get_syscall_name(regs.orig_rax));
				(rdi) ? (printf("%ld", rdi)) : printf("0");
				(rsi) ? (printf(", %ld", rsi)) : 0;
				(rdx) ? (printf(", %ld", rdx)) : 0;
				(r10) ? (printf(", %ld", r10)) : 0;
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
