/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:14:43 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 23:22:52 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_line(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->print_mutex));
	if (philo->data->death == 0)
		printf("%lld\t%d, %s\n", timestamp(), philo->pos, str);
	pthread_mutex_unlock(&(philo->data->print_mutex));
}
