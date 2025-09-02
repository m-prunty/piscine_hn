/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 04:34:11 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 05:05:43 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	n;
	int	i;

	n = max - min;
	i = 0;
	*range = NULL;
	if (n <= 0)
		return (-1);
	*range = malloc(sizeof(int) * n);
	if (*range != NULL)
	{
		while (min < max)
		{
			(*range)[i] = min++;
			i++;
		}
	}
	return (n);
}
/*
#include <stdio.h>
int	maina)
{
int *r;

printf("%i\n",ft_ultimate_range(&r,7,26));
printf("%i\n",ft_ultimate_range(&r,-2,10));
}
 */
