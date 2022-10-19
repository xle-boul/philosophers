/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:29:45 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 00:22:40 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_if_dead(t_data *all, int i)
{
	if ((int)timestamp() - all->philo[i].last_meal_time > all->ttdie)
	{
		print_line(&(all->philo[i]), "died");
		pthread_mutex_lock(&(all->print_mutex));
		all->end = 1;
		return (true);
	}
	return (false);
}

bool	check_if_finished(t_data *all)
{
	int	i;
	int	count;

	while (all->end == 0)
	{
		i = 0;
		count = 0;
		while (i < all->num_of_philo && all->end == 0)
		{
			if (check_if_dead(all, i) == true)
				return (true);
			if (all->philo[i].meals >= all->must_eat && all->must_eat != 0)
				count++;
			i++;
		}
		if (count == i)
		{
			all->end = 1;
			pthread_mutex_lock(&(all->print_mutex));
			printf("all the philos ate at least %d times\n", all->must_eat);
			return (true);
		}
	}
	return (false);
}

int	dinner(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->num_of_philo)
	{
		all->philo[i].last_meal_time = timestamp();
		if (pthread_create(&(all->philo[i].thread),
				NULL, routine, &all->philo[i]))
		{
			all->error = 3;
			return (1);
		}
		i++;
	}
	if (check_if_finished(all) == true)
		pthread_mutex_unlock(&(all->print_mutex));
	while (--i >= 0)
		pthread_join(all->philo[i].thread, NULL);
	return (0);
}

void	only_one_philo(t_data *all)
{
	printf("%lld\t1, has taken a fork\n", timestamp());
	philo_sleep(all->ttdie);
	printf("%lld\t1, died\n", timestamp());
}
