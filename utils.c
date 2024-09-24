/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:42:55 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/24 13:14:58 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_all_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->monitor);
	while (i <= data->n_philo)
	{
		if (data->fail == true)
		{
			pthread_mutex_unlock(&data->monitor);
			return (0);
		}
		else if (data->threads_ok == true)
		{
			pthread_mutex_unlock(&data->monitor);
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->monitor);
	return (1);
}

void	clean_forks(t_data *data)
{
	int	i;

	i = 0;
	while (&data->philos[i] && i < data->n_philo)
	{
		if (&data->philos[i])
			pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

void	clean_destroy(t_data *data)
{
	if (data)
	{
		if (data->philos)
		{
			clean_forks(data);
			pthread_mutex_destroy(&data->monitor);
			pthread_mutex_destroy(&data->print);
			pthread_mutex_destroy(&data->finish);
			free(data->philos);
		}
	}
	return ;
}

long	ft_atol(const char *str)
{
	int		i;
	int		sin;
	long	res;

	i = 0;
	sin = 1;
	res = 0;
	if (str[i] == 45)
	{
		sin *= -1;
		i++;
	}
	while (str[i] == 45 || str[i] == 43)
		i++;
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sin);
}
