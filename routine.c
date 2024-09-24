/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:40 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/24 12:58:58 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;
	size_t			momemt;

	gettimeofday(&time, NULL);
	momemt = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (momemt);
}

void	print_act(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->finish);
	if (!philo->data->dead && !philo->data->full)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ld %d %s\n",
			get_time() - philo->data->start, philo->philo_id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->finish);
}

void	*just_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_act(philo, "has taken a fork");
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

int	dinner_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish);
	if (philo->data->dead || philo->data->full)
	{
		pthread_mutex_unlock(&philo->data->finish);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->finish);
	return (0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (!wait_all_philos(philo->data))
		return (NULL);
	if (philo->data->n_philo == 1)
		return (just_one(philo));
	if (philo->philo_id % 2 == 0)
		my_sleep(10, philo);
	while (!dinner_finish(philo))
	{
		if (philo->philo_id % 2 != 0)
			eat(philo, philo->left_fork, philo->rigth_fork);
		else
			eat(philo, philo->rigth_fork, philo->left_fork);
		p_sleep(philo);
		think(philo);
	}
	return (NULL);
}
