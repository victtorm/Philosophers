/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:26:05 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/23 12:40:18 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_data *data, int i)
{
	if ((get_time() - data->start) - data->philos[i].last_meal
		>= (size_t)data->time_die)
	{
		print_act(&data->philos[i], "died");
		pthread_mutex_lock(&data->finish);
		data->dead = true;
		pthread_mutex_unlock(&data->finish);
		pthread_mutex_unlock(&data->monitor);
		return (0);
	}
	return (1);
}

int	check_meals(t_data *data)
{
	int	i;
	int	all_full;

	i = 0;
	all_full = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].full == true)
			all_full++;
		i++;
	}
	if (all_full == data->n_philo)
	{
		pthread_mutex_lock(&data->finish);
		data->full = true;
		pthread_mutex_unlock(&data->finish);
		pthread_mutex_unlock(&data->monitor);
		return (0);
	}
	return (1);
}

void	monitor(t_data *data)
{
	int	i;

	while (42)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->monitor);
			if (!check_die(data, i))
				return ;
			if (!check_meals(data))
				return ;
			pthread_mutex_unlock(&data->monitor);
			i++;
		}
	}
	return ;
}

void	join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philos[i].thread_p, NULL) != 0)
			return ;
		i++;
	}
}

void	start_dinner(t_data *data)
{
	int	i;

	i = 0;
	data->start = get_time();
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread_p,
				NULL, &routine, &data->philos[i]) != 0)
		{
			clean_destroy(data);
			return ;
		}
		i++;
	}
	pthread_mutex_lock(&data->monitor);
	data->threads_ok = true;
	pthread_mutex_unlock(&data->monitor);
	monitor(data);
	join_philos(data);
}
