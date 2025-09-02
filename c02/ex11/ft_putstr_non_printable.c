/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:55:12 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/18 21:48:33 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int nb)
{
	char	*hex;
	int		hexes;
	int		units;

	hex = "0123456789abcdef";
	hexes = nb / 16;
	units = nb % 16;
	ft_putchar('\\');
	ft_putchar(hex[hexes]);
	ft_putchar(hex[units]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_puthex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*
int	main()
{
	char	i;

	i = -1;
	while (++i <= 127 && i >=0)
		ft_putstr_non_printable(&i);

	ft_putchar('\n');
	ft_putstr_non_printable("Hello\nHow are you?\v");
	ft_putstr_non_printable("Hello\nHow are you?\v");
	ft_putstr_non_printable("Hello\x7FHow are you?");
}
*/
