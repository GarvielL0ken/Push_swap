/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:55:01 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/06 14:59:18 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(int argc, char *argv[])
{
	int fd;
	int	arr[100];
	int i;
	int sum;
	int min;
	int max;
	char *line;

	i = 0;
	sum = 0;
	min = -1;
	max = -1;
	if (argc == 2)
	{
		fd = open(argv[1], O_WRONLY | O_APPEND);
		get_next_line(0, &line);
		line += 4;
		//write(1, line, ft_strlen(line));
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
	if (argc == 3)
	{
		fd = open(argv[1], 'r');
		while (get_next_line(fd, &line))
		{
			arr[i] = atoi(line);
			if (min == -1 || arr[i] < min)
				min = arr[i];
			if (max == -1 || max < arr[i])
				max = arr[i];
			sum += arr[i];
			i++;
		}
		printf("number of data points = %d\nsum = %d\n", i, sum);
		sum = sum / i;
		printf("average = %d\nmin = %d\nmax = %d\nrange = %d\n", sum, min, max, max - min);
	}

}
