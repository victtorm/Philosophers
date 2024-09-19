/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:05:46 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/19 18:21:44 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->rigth_fork);
	print_act(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_act(philo, "has taken a fork");
	print_act(philo, "is eating");
	pthread_mutex_lock(&philo->data->monitor);
	philo->last_meal = get_time() - philo->data->start;
	pthread_mutex_unlock(&philo->data->monitor);
	usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->rigth_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->data->monitor);
	philo->n_meals++;
	if (philo->n_meals == philo->data->meals)
		philo->full = true;
	pthread_mutex_unlock(&philo->data->monitor);
}

void	p_sleep(t_philo *philo)
{
	print_act(philo, "is sleeping");
	usleep(philo->data->time_sleep);
}

void	think(t_philo *philo)
{
	print_act(philo, "is thinking");
	if (philo->data->n_philo % 2 != 0)
		usleep(1);
}
