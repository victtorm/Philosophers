/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:05:46 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/24 10:49:09 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(size_t time, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		pthread_mutex_lock(&philo->data->monitor);
		if (philo && philo->data && philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->monitor);	
			break ;
		}
		pthread_mutex_unlock(&philo->data->monitor);
		usleep(500);
	}
}

void	eat(t_philo *philo,
	pthread_mutex_t *fork_one, pthread_mutex_t *fork_two)
{
	pthread_mutex_lock(fork_one);
	print_act(philo, "has taken a fork");
	pthread_mutex_lock(fork_two);
	print_act(philo, "has taken a fork");
	print_act(philo, "is eating");
	pthread_mutex_lock(&philo->data->monitor);
	philo->last_meal = get_time() - philo->data->start;
	pthread_mutex_unlock(&philo->data->monitor);
	my_sleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(fork_one);
	pthread_mutex_unlock(fork_two);
	pthread_mutex_lock(&philo->data->monitor);
	philo->n_meals++;
	if (philo->n_meals == philo->data->meals)
		philo->full = true;
	pthread_mutex_unlock(&philo->data->monitor);
}

void	p_sleep(t_philo *philo)
{
	print_act(philo, "is sleeping");
	my_sleep(philo->data->time_sleep, philo);
}

void	think(t_philo *philo)
{
	print_act(philo, "is thinking");
	if (philo->data->n_philo % 2 != 0)
		my_sleep(1, philo);
}
