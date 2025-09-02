/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 05:42:41 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/06 15:03:05 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putint(int n)
{
	n = n + 48;
	write(1, &n, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1 ;
			while (k < 10)
			{
				ft_putint(i);
				ft_putint(j);
				ft_putint(k);
				if ((i == 7 ) && (j == 8) && (k == 9))
					return ;
				write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

/*
int main()
{
	ft_print_comb();
}
*/
