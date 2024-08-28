/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multforks_teste.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:09:42 by vbritto-          #+#    #+#             */
/*   Updated: 2024/08/27 16:23:19 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int	main(int argc, char **argv)
{
	int	id1;
	int	id2;

	id2 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("we are on process y\n");
		else
			printf("we are on process x\n");
	}
	else
	{
		if (id2 ==0)
			printf("we are on process z\n");
		else
			printf("we are on parent process\n");
	}
	while (wait(NULL) != -1)
		printf("Wait for child\n");
	return (0);
}