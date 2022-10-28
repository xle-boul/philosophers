/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:32:04 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 16:02:18 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_loop(t_philo *philo)
{
	while (philo->data->end == 0)
	{
		pthread_mutex_unlock(&(philo->data->lock));
		pthread_mutex_lock(philo->l_fork);
		print_line(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_line(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->data->lock));
		philo->last_meal_time = (int)timestamp(&(philo->data->time_mutex));
		pthread_mutex_unlock(&(philo->data->lock));
		print_line(philo, "is eating");
		philo_sleep(&(philo->data->time_mutex), philo->data->tteat);
		pthread_mutex_lock(&(philo->data->lock));
		philo->meals++;
		pthread_mutex_unlock(&(philo->data->lock));
		print_line(philo, "is sleeping");
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo_sleep(&(philo->data->time_mutex), philo->data->ttsleep);
		print_line(philo, "is thinking");
		pthread_mutex_lock(&(philo->data->lock));
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->pos % 2 != 0)
		philo_sleep(&(philo->data->time_mutex), 5);
	pthread_mutex_lock(&(philo->data->lock));
	routine_loop(philo);
	pthread_mutex_unlock(&(philo->data->lock));
	return (NULL);
}
