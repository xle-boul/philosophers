/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:02 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/19 23:59:26 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				pos;
	int				meals;
	int				last_meal_time;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				error;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				num_of_philo;
	int				must_eat;
	int				end;
	t_philo			*philo;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
}				t_data;

// error handler
void		error_handler(int error);
void		error_handler_free(int error, t_data *all);

// free
void		free_stuff(t_data *all);

// parsing
int			check_arguments(int ac, char **av);
int			check_data(char **av, t_data *all);

// init_structs
int			init_philo(t_data *all);
int			init_forks(t_data *all);

// dinner
bool		check_if_finished(t_data *all);
int			dinner(t_data *all);
void		only_one_philo(t_data *all);

// thread_routine
void		*routine(void *arg);

// utilities
long		ft_atol(const char *str);
long long	timestamp(void);
void		print_line(t_philo *philo, char *str);
void		philo_sleep(int given_time);

#endif