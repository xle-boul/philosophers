/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:27:45 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 16:04:54 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_data *all)
{
	int		i;

	i = 0;
	all->philo = malloc(sizeof(t_philo) * all->num_of_philo);
	if (!all->philo)
	{
		all->error = 2;
		return (1);
	}
	while (i < all->num_of_philo)
	{
		all->philo[i].pos = i + 1;
		all->philo[i].last_meal_time = 0;
		all->philo[i].l_fork = &(all->forks_mutex[i]);
		all->philo[i].r_fork = &(all->forks_mutex[(i + 1) % all->num_of_philo]);
		all->philo[i].data = all;
		all->philo[i].meals = 0;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *all)
{
	if (pthread_mutex_init((&all->print_mutex), NULL)
		|| pthread_mutex_init(&(all->time_mutex), NULL)
		|| pthread_mutex_init(&(all->lock), NULL))
	{
		all->error = 3;
		return (1);
	}
	return (0);
}

int	init_forks(t_data *all)
{
	int	i;

	i = 0;
	all->forks_mutex = malloc(sizeof(pthread_mutex_t) * all->num_of_philo);
	if (!all->forks_mutex)
	{
		all->error = 2;
		return (1);
	}
	while (i < all->num_of_philo)
	{
		if (pthread_mutex_init((&all->forks_mutex[i]), NULL))
		{
			all->error = 3;
			return (1);
		}
		i++;
	}
	if (init_mutex(all) != 0)
		return (1);
	return (0);
}
