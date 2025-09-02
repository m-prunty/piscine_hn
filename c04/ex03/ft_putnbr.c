/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 05:12:41 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/16 06:29:03 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int c)
{
	ft_putchar(c + 48);
}

void	ft_putnbr(int nb)
{
	long	lnb;

	if (nb == 1 << 31)
	{
		lnb = ~(long)(1 << 31) + 1;
		ft_putnbr(-lnb / 10);
		ft_putnum(lnb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putnum(nb % 10);
	}
	else
		ft_putnum(nb % 10);
}
/*
#include <stdio.h>
int	main()
{
	ft_putnbr(12345);
	ft_putchar('\n');
	ft_putnbr(-12345);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr((1<<31));
	ft_putchar('\n');
	ft_putnbr(~(1<<31));
	ft_putchar('\n');
}
*/
