/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victtormoraes <victtormoraes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:12:36 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/15 19:31:00 by victtormora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_fork(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->n_philo * (sizeof(t_philo)));
	if (!data->forks)
		return (NULL);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (error);
		i++;
	}
	if (pthread_mutex_init(&data->monitor, NULL) != 0)
		return (error);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (error);
	if (pthread_mutex_init(&data->finish, NULL) != 0)
		return (error);
}

void	*start_more(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(data->n_philo * (sizeof(t_philo)));
	if (!data->philos)
		return (NULL);
	while (i < data->n_philo)
	{
		data->philos[i].philo_id = 1 + i;
		data->philos[i].n_meals = 0;
		data->philos[i].full = 0;
		data->philos[i].last_meal = 0;
		if (1 + i = data->n_philo)
			data->philos[i].rigth_fork = &data->forks[0];
		else
			data->philos[i].rigth_fork = &data->forks[i + 1];
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].data = data;
		i++;
	}
	start_forks(data);
}

void	start_data(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->meals = -1; 
	if (argc == 6)
		data->meals = ft_atoi(argv[5]);
	data->threads_ok = 0;
	data->full = 0;
	data->dead = 0;
	start_more(data);
	
}