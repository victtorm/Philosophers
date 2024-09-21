/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:05:46 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/21 13:54:10 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(500);
}

void	eat(t_philo *philo, pthread_mutex_t *fork_one, pthread_mutex_t *fork_two)
{
	pthread_mutex_lock(fork_one);
	print_act(philo, "has taken a fork");
	pthread_mutex_lock(fork_two);
	print_act(philo, "has taken a fork");
	print_act(philo, "is eating");
	pthread_mutex_lock(&philo->data->monitor);
	philo->last_meal = get_time() - philo->data->start;
	pthread_mutex_unlock(&philo->data->monitor);
	ft_usleep(philo->data->time_eat);
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
	ft_usleep(philo->data->time_sleep);
}

void	think(t_philo *philo)
{
	print_act(philo, "is thinking");
	if (philo->data->n_philo % 2 != 0)
		ft_usleep(1);
}
