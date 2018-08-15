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


int	main(void)
{
	pid_t			child;
	int status;
	int flag;
	long rax;
	long rdi;
	long rsi;
	long rdx;
	long r10;
	int ret;

	ret = 0;
	flag = 0;
	status = 0;
	child = fork();
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	ptrace(PTRACE_INTERRUPT, child, 0, 0);
	if (child == 0)
	{
		char * const args[] =  {NULL};
		execve("./coucou", args, NULL);
	} 
	else 
	{
		struct user_regs_struct regs;
		while (42)
		{
			wait_for_syscall(child , &status);
			ptrace(PTRACE_GETREGS, child , NULL, &regs);
			if (flag == 0)
			{
				flag = 1;
				//	printf("rsi -> %ld old rsi -> %ld\n", rsi , old_rsi);
				printf("%s(", get_syscall_name(regs.orig_rax));
				rdi = ptrace(PTRACE_PEEKUSER, child, RDI * 8, NULL);
				rsi = ptrace(PTRACE_PEEKUSER, child, RSI * 8, NULL);
				rdx = ptrace(PTRACE_PEEKUSER, child, RDX * 8, NULL);
				r10 = ptrace(PTRACE_PEEKUSER, child, R10 * 8, NULL);
				rax = ptrace(PTRACE_PEEKUSER, child, RAX * 8, NULL);
				(rdi) ? (get_data(child, rdi, 0)) : printf("0");
				(rsi) ? (get_data(child, rsi, 1)) : 0;
				(rdx) ? (get_data(child, rdx, 1)) : 0;
				(r10) ? (get_data(child, r10, 1)) : 0;
				if (rax == -1)
					printf(") => ?\n");
				else if (rax < -1)
				{
					printf(") => -1 %s\n", get_errno_name(rax));
				}
				else
					printf(") => %ld\n", rax);
				regs.rdi = 0;
				ptrace(PTRACE_SETREGSET, child , NULL,&regs);
			}
			else
			{
				flag = 0;
			}
			if (ret = WIFEXITED(status))
				break ;
		}
		printf("+++ exited with %d +++\n", ret);
	}
	return (0);
}
