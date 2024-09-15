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


typedef struct philo
{
    int				philo_id;
    int				n_meals;
    bool			full;
    long			last_meal;
    pthread_t		thread_p;
    pthread_mutex_t	*rigth_fork;
    pthread_mutex_t	*left_fork;
    struct s_data	*data;
    
}   t_philo;


typedef struct s_data
{
    int				n_philo;
    long 			time_die;
    long			time_eat;
    long			time_sleep;
    int				meals;
    long			start;
    bool			threads_ok;
    bool			dead;
    bool			full;
    t_philo			*philos;
    pthread_mutex_t	monitor;
    pthread_mutex_t	print;
    pthread_mutex_t	*forks;
    pthread_mutex_t	finish;
}   t_data;


// CHECK.C

int	    ft_isdigit(int c);
void    check_philo_args(int argc, bool *just_number, char	**argv);
int	    check_philo(int argc, char **argv);
int     ft_atoi(const char *str);

// START_PHILO.C

void	start_data(t_data *data, int argc, char **argv);

#endif