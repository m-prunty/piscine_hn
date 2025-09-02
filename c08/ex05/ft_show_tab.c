/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:18:39 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 07:43:46 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
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
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 10)
		ft_putnbr(nb / 10);
	ft_putnum(nb % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (++i)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
	}
}
