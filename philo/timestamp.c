/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:08:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 11:29:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	timestamp(pthread_mutex_t *time_mutex)
{
	static long long			timer = 0;
	struct timeval				time_value;

	if (time_mutex)
		pthread_mutex_lock(time_mutex);
	gettimeofday(&time_value, NULL);
	if (timer == 0)
		timer = time_value.tv_sec * 1000 + time_value.tv_usec / 1000;
	if (time_mutex)
		pthread_mutex_unlock(time_mutex);
	return ((time_value.tv_sec * 1000 + time_value.tv_usec / 1000)
		- timer);
}
