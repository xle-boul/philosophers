/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:26:22 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 22:26:47 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arguments(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (1);
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!('0' <= (av[i][j]) && (av[i][j]) <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_data(char **av, t_data *all)
{
	all->error = 0;
	all->death = 0;
	all->num_of_philo = ft_atol(av[1]);
	all->ttdie = ft_atol(av[2]);
	all->tteat = ft_atol(av[3]);
	all->ttsleep = ft_atol(av[4]);
	if (av[5] != NULL)
		all->must_eat = ft_atol(av[5]);
	if (all->num_of_philo <= 0
		|| all->ttdie < 0
		|| all->tteat < 0
		|| all->ttsleep < 0)
		return (1);
	if (av[5] != NULL)
		if (all->must_eat <= 0)
			return (1);
	return (0);
}
