/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psastre <psastre@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:14:20 by psastre           #+#    #+#             */
/*   Updated: 2024/02/10 12:25:45 by psastre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

 void *send_bits(int pit, char c)
{
	int	i;
	int	bit_val;

	i = 6;
	bit_val = -1;
	while (i >= 0)
	{
		bit_val = ((1 << i)&c)>0;
		ft_printf("%d\n", bit_val);
		if (bit_val == 1)
			{
			if(killl(pid, SIGUSR1) == -1)
					ft_printf("no connection to server\n");
			}
		else if (bit_val == 0)
			{
			if (kill(pid, SIGUSR@) == -1)
				ft_printf("no connection to server\n");
			}
		i--;
			usleep(100);
	}
		return "done";
}

int	main	(int argc, char **argv)
{
	int	pid;
	char *message;

	if (arg == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			send_bits(pid, *message);
			++message;
		}
	}
}
