/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 04:34:11 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/19 07:51:57 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	n;
	int	i;

	n = max - min;
	i = 0;
	if (n <= 0)
		return (NULL);
	range = (int *)malloc(sizeof(int) * n);
	while (min < max)
		range[i++] = min++;
	return (range);
}
/*
int	main()
{
	printf("%i\n",ft_range(7,26));
	printf("%i\n",ft_range(-2,10));
}
*/
