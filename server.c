/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psastre <psastre@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:33:19 by psastre           #+#    #+#             */
/*   Updated: 2024/02/03 14:00:49 by psastre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	handle(int sig)
{
	static int bit = 0; 
	static int 	c = 0;

	c <<= 1;
	if (sig == SIGUSR1)
	{
		c |= 1;
	}
	bit ++; 
	if (bit == 7)
	{
		ft_printf("%c", c); 
		bit = 0; 
		c = 0;
	}
}

void	cont(void)
{
	struct sigaction sa; 

	sa.sa_handler = handle; 
	sa.sa_flags = SA_RESTART: 

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main()
{
	int pid; 

	pid = getpid();
	if (!pid)
		ft_printf("NO PID");
	else
		ft_printf("Your PIS is %\n", pid);
	cont ();
	while (1)
		pause();
	return(0);
}
