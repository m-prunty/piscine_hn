/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 05:12:41 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 05:05:52 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_isvalid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(base);
	if (len > 1)
	{
		while (base[++i])
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			else
			{
				j = -1;
				while (++j < i)
					if (base[j] == base[i])
						return (0);
			}
		}
		return (i);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	lnb;
	int		base_len;

	base_len = ft_isvalid_base(base);
	if (base_len)
	{
		if (nbr == 1 << 31)
		{
			lnb = ~(long)(1 << 31) + 1;
			ft_putnbr_base(-lnb / base_len, base);
			ft_putchar(base[lnb % base_len]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= base_len)
			ft_putnbr_base(nbr / base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
}

/*
#include <stdio.h>
int	main()
{
ft_putnbr_base(12345, "001123456789");
ft_putchar('\n');
//ft_putnbr_base(-12345, "0abccde1");
ft_putchar('\n');
//ft_putnbr_base(0, "abcd");
ft_putchar('\n');
//printf("%i", ~(1<<31));
//printf("%i", (1<<31));
ft_putnbr_base((1<<31), "01");
ft_putchar('\n');
ft_putnbr_base(~(1<<31), "0123456789");
ft_putchar('\n');
}
*/
