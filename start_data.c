/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:12:36 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/23 12:39:49 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->n_philo * (sizeof(pthread_mutex_t)));
	if (!data->forks)
		return (NULL);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			data->fail = true;
			return (NULL);
		}
		i++;
	}
	if (pthread_mutex_init(&data->monitor, NULL) != 0
		|| pthread_mutex_init(&data->print, NULL) != 0
		|| pthread_mutex_init(&data->finish, NULL) != 0)
	{
		clean_destroy(data);
		return (NULL);
	}
	return (NULL);
}

void	*start_all(t_data *data)
{
	int	i;

	i = 0;
	start_forks(data);
	data->philos = malloc(data->n_philo * (sizeof(t_philo)));
	if (!data->philos)
		return (NULL);
	while (i < data->n_philo)
	{
		data->philos[i].philo_id = 1 + i;
		data->philos[i].n_meals = 0;
		data->philos[i].full = 0;
		data->philos[i].last_meal = 0;
		if (i + 1 == data->n_philo)
			data->philos[i].rigth_fork = &data->forks[0];
		else
			data->philos[i].rigth_fork = &data->forks[i + 1];
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].data = data;
		i++;
	}
	return (NULL);
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
	data->fail = 0;
	start_all(data);
}
