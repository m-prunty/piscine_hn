/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:41:03 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/18 19:45:05 by maprunty         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int	i;

	i = ac;
	if (ac >= 2)
	{
		while (--i > 0)
		{
			ft_putstr(av[i]);
			ft_putchar('\n');
		}
	}
	return (0);
}
