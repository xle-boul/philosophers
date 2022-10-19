/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:22 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 22:34:41 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_stuff(t_data *all)
{
	int	i;

	i = 0;
	if (&(all->philo[0]))
		free(all->philo);
	if (&(all->forks_mutex[0]))
	{
		while (i < all->num_of_philo)
		{
			pthread_mutex_destroy(&(all->forks_mutex[i]));
			i++;
		}
		free(all->forks_mutex);
	}
	pthread_mutex_unlock(&(all->print_mutex));
	pthread_mutex_destroy(&(all->print_mutex));
}
