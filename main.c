/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:19:39 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/19 18:25:19 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_philo(argc, argv))
		return (0);
	start_data(&data, argc, argv);
	start_dinner(&data);
	//clean_destroy(&data);
	return (1);
}
