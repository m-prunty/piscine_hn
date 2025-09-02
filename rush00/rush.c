/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:14:54 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/02 21:10:32 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_string(char *buffer)
{
	while (*buffer != '\0')
	{
		write(1, &(*buffer), 1);
		(*buffer++);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	row(int x, int x1, int y, int y1)
{
	while (x1 <= x - 1)
	{
		if (y1 == 0 || y1 == y - 1)
		{
			if (x1 == 0)
				ft_putchar('A');
			else
			{
				if (x1 == x - 1)
					ft_putchar('C');
				else
					ft_putchar('B');
			}
		}
		else
		{
			if (x1 == 0 || x1 == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		x1++;
	}
}

void	rush(int x, int y)
{
	int	x1;
	int	y1;

	if (x > 0 && y > 0)
	{
		x1 = 0;
		y1 = 0;
		while (y1 <= y - 1)
		{
			row(x, x1, y, y1);
			y1++;
			ft_putchar('\n');
			x1 = 0;
		}
	}
	else
	{
		print_string("ERROR: Invalid parameters");
	}
}


