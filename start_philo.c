/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:12:36 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/27 13:20:34 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo, char	**argv)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->meals = ft_atoi(argv[5]);
}