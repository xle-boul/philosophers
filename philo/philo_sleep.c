/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:06:02 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/18 23:50:39 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleep(int given_time)
{
	int	target_time;

	target_time = timestamp() + given_time;
	while (timestamp() < target_time)
		usleep(100);
}
