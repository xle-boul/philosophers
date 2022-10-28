/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:33:47 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:57 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	all;

	if (check_arguments(ac, av) != 0)
		error_handler(0);
	if (check_data(av, &all) != 0)
		error_handler(1);
	if (all.num_of_philo == 1)
	{
		only_one_philo(&all);
		return (0);
	}
	if (init_forks(&all) != 0)
		error_handler_free(all.error, &all);
	if (init_philo(&all) != 0)
		error_handler_free(all.error, &all);
	if (dinner(&all) != 0)
		error_handler_free(all.error, &all);
	free_stuff(&all);
	return (0);
}
