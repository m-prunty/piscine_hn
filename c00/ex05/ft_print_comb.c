/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 05:42:41 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/06 16:09:31 by maprunty         ###   ########.fr       */
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
	int	iarr[3];

	iarr[0] = 0;
	iarr[1] = 0;
	iarr[2] = 0;
	while (iarr[0] < 8)
	{
		iarr[1] = iarr[0] + 1;
		while (iarr[1] < 9)
		{
			iarr[2] = iarr[1] + 1 ;
			while (iarr[2] < 10)
			{
				ft_putint(iarr[0]);
				ft_putint(iarr[1]);
				ft_putint(iarr[2]);
				if ((iarr[0] == 7) && (iarr[1] == 8) && (iarr[2] == 9))
					return ;
				write(1, ", ", 2);
				iarr[2]++;
			}
			iarr[1]++;
		}
		iarr[0]++;
	}
}

/*
int main()
{
	ft_print_comb();
}
*/
