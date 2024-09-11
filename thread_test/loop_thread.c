/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:13:15 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/28 16:28:08 by vbritto-         ###   ########.fr       */
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

	while (i < 1000)
	{
		//pthread_mutex_lock(&mutex);
		mails++;
		//pthread_mutex_unlock(&mutex);
		i++;

	}
}

int	main(int argc, char **argv)
{
	pthread_t	th[4];
	int i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
			return (1);
		printf("thread %d start\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
		printf("thread %d end\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("%d\n", mails);
	return (0);
}
