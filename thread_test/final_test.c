/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:21:52 by vbritto-          #+#    #+#             */
/*   Updated: 2024/09/03 18:36:49 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
//pthread_mutex_t  mutex;

void	*routine(void *arg)
{
	int index;

	index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int i;
	int *a;

	i = 0;
	//pthread_mutex_init(&mutex, NULL);
	while (i < 10)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
		i++;
	}
	//pthread_mutex_destroy(&mutex);
	//printf("%d\n", mails);
	return (0);
}