/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:24:49 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 22:55:16 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_handler(int error)
{
	if (error == 0)
		printf("Error: please provide 5 or 6 numeric arguments\n");
	if (error == 1)
		printf("Error: data provided invalid\n");
	if (error == 2)
		printf("Error: malloc failed\n");
	if (error == 3)
		printf("Error: pthread failed\n");
	exit (EXIT_FAILURE);
}

void	error_handler_free(int error, t_data *all)
{
	if (error == 0)
		printf("Error: please provide 5 or 6 numeric arguments\n");
	if (error == 1)
		printf("Error: data provided invalid\n");
	if (error == 2)
		printf("Error: malloc failed\n");
	if (error == 3)
		printf("Error: pthread failed\n");
	free_stuff(all);
	exit (EXIT_FAILURE);
}