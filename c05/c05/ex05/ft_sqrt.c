/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 02:44:10 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/19 16:21:42 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nb == 1)
		return (1);
	if (nb > 2)
	{
		while (nb > 0 && (j++ + ++i))
			nb -= (i++);
		if (nb < 0)
			return (0);
	}	
	return (j);
}

/*
#include <stdio.h>
int	main()
{
	printf("%i",ft_sqrt(0));
	printf("%i",ft_sqrt(-10));
	printf("%i",ft_sqrt(100));
	printf("%i",ft_sqrt(101));
	printf("%i",ft_sqrt(99));
}
*/
/*
   int ft_sqrt(int nb)
   {	
   int i;

   if (nb == 1)
   return (1);
   if (nb > 2)
   {
   i = nb / 2;
   while (i--)
   if (i * i == nb)
   return (i);
   }
   return (0);
   }
 */
