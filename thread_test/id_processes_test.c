/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_processes_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:58:04 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/27 16:11:59 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int	main(int argc, char **argv)
{
	int	id;

	id = fork();
	if (id == 0)
		sleep(2);
	printf("Current ID: %d\nParent ID: %d\n", getpid(), getppid());

	if (id != 0) // Precisa esperar o processo filho acabar (teste sem esse if se quiser)
		wait(NULL);
	return (0);
}