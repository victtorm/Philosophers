/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:46:20 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/19 14:43:21 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sin;
	int	res;

	n = 0;
	sin = 1;
	res = 0;
	while (str[n] == 32 || (str[n] >= 9 && str[n] <= 13))
		n++;
	if (str[n] == 45 || str[n] == 43)
	{
		if (str[n] == 45)
			sin *= -1;
		n++;
	}
	while (str[n] != '\0' && str[n] >= 48 && str[n] <= 57)
	{
		res *= 10;
		res += str[n] - '0';
		n++;
	}
	return (res * sin);
}

void	check_intmax(char **argv, bool *just_number)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX)
			(*just_number) = false;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}

void	check_philo_args(int argc, bool *just_number, char	**argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!ft_isdigit(argv[i][j]) || (ft_atoi(argv[i]) <= 0))
			(*just_number) = false;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				(*just_number) = false;
			j++;
		}
		i++;
	}
}

int	check_philo(int argc, char **argv)
{
	bool	just_number;

	just_number = true;
	if (argc == 5 || argc == 6)
	{
		check_philo_args(argc, &just_number, argv);
		check_intmax(argv, &just_number);
	}
	else
		just_number = false;
	if (just_number == false)
	{
		printf ("ERROR\n");
		printf ("Try: ./philo [philos] [t_die] [t_eat] [t_sleep] [meals]\n");
		printf ("The number of philos need to be 1 or more\n");
		printf ("Only possible to use positive numbers inside int range\n");
		return (0);
	}
	return (1);
}
