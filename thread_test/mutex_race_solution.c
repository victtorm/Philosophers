/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_race_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:14 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/28 15:54:00 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t  mutex;

void	*routine()
{
	int i = 0;

	while (i < 100000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;

	}
}

int	main(int argc, char **argv)
{
	pthread_t	t1, t2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);
	printf("%d\n", mails);
	return (0);
}