/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victtormoraes <victtormoraes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:19:39 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/15 19:54:08 by victtormora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*memdata(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	memset(data, 0, sizeof(t_data));
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_philo(argc, argv))
		return (0);
	start_data(&data, argc, argv);
	start_diner(data);
	free(&data);
	return (1);
}
