/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:06:02 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 11:19:14 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleep(pthread_mutex_t *time_mutex, int given_time)
{
	int	target_time;

	target_time = timestamp(time_mutex) + given_time;
	while (timestamp(time_mutex) < target_time)
		usleep(100);
}
