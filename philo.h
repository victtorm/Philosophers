/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:21:32 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/23 12:38:56 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct philo
{
	int				philo_id;
	int				n_meals;
	bool			full;
	size_t			last_meal;
	pthread_t		thread_p;
	pthread_mutex_t	*rigth_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				meals;
	size_t			start;
	bool			threads_ok;
	bool			dead;
	bool			full;
	bool			fail;
	t_philo			*philos;
	pthread_mutex_t	monitor;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish;
}	t_data;

// CHECK.C

void	check_intmax(char **argv, bool *just_number);
int		ft_isdigit(int c);
void	check_philo_args(int argc, bool *just_number, char	**argv);
int		check_philo(int argc, char **argv);
int		ft_atoi(const char *str);

// UTILS.c

long	ft_atol(const char *str);
void	clean_destroy(t_data *data);
void	clean_forks(t_data *data);
int		wait_all_philos(t_data *data);

// START_DATA.C

void	start_data(t_data *data, int argc, char **argv);
void	*start_more(t_data *data);
void	*start_forks(t_data *data);
int		finish_mutex(t_data *data, int i);

// STAR_DINNER.C

void	start_dinner(t_data *data);
void	join_philos(t_data *data);
void	monitor(t_data *data);
int		check_meals(t_data *data);
int		check_die(t_data *data, int i);

// ROUTINE.C

int		dinner_finish(t_philo *philo);
void	*just_one(t_philo *philo);
void	print_act(t_philo *philo, char *str);
size_t	get_time(void);
void	*routine(void *philos);

// ACTS.C

void	eat(t_philo *philo,
			pthread_mutex_t *fork_one, pthread_mutex_t *fork_two);
void	p_sleep(t_philo *philo);
void	think(t_philo *philo);
void	my_usleep(size_t time);

#endif