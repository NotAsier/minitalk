/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:19:53 by aarranz-          #+#    #+#             */
/*   Updated: 2023/10/23 09:27:40 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r);
}

void	send(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{	
		bit = (c >> i) & 1;
		kill (pid, SIGUSR1 + bit);
		usleep (500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(1, "error\n", 6);
		return (2);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "invalid pid\n", 12);
		exit(EXIT_FAILURE);
	}
	while (av[2][i] != '\0')
	{
		send(av[2][i], pid);
		i++;
	}
	return (0);
}
