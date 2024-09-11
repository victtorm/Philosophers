/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:48:2s3 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/27 12:45:33 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>




typedef struct s_data
{
    int n_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int meals;
}   t_data;


// CHECK.C

int	    ft_isdigit(int c);
void    check_philo_args(int argc, bool *just_number, char	**argv);
int	    check_philo(int argc, char **argv);
int     ft_atoi(const char *str);

// START_PHILO.C

void	start_data(t_data *data, int argc, char **argv);

#endif