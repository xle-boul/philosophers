/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:32:04 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 23:59:26 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->pos % 2 != 0)
		philo_sleep(2);
	while (philo->data->end == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_line(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_line(philo, "has taken a fork");
		philo->last_meal_time = (int)timestamp();
		print_line(philo, "is eating");
		philo_sleep(philo->data->tteat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->meals++;
		print_line(philo, "is sleeping");
		philo_sleep(philo->data->ttsleep);
		print_line(philo, "is thinking");
	}
	return (NULL);
}
