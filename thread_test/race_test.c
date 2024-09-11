/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:29:05 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/28 15:32:23 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void	*routine()
{
	int i = 0;

	while (i < 100000000)
	{
		mails++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_t	t1, t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("%d\n", mails);
	return (0);
}