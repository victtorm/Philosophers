/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:19:39 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/11 09:53:03 by vbritto-         ###   ########.fr       */
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
	t_data	*data;

	if (!check_philo(argc, argv))
		return (0);
	data = NULL;
	data = memdata(data);
	start_data(data, argc, argv);
	start_lunch(data);
	printf ("OK");
	free(data);
	return (1);
}
