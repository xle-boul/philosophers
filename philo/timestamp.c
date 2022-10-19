/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:08:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/09 22:18:50 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	timestamp(void)
{
	static long long		timer = 0;
	struct timeval			time_value;

	gettimeofday(&time_value, NULL);
	if (timer == 0)
		timer = time_value.tv_sec * 1000 + time_value.tv_usec / 1000;
	return ((time_value.tv_sec * 1000 + time_value.tv_usec / 1000)
		- timer);
}
