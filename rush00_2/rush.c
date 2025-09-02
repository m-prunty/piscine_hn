/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:14:54 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/03 20:56:27 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


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

char	*get_charset(void)
{
	char	*charset[5];
	int  g_rushn;
	
	charset[0] = "oooo-|";
	charset[1] = "/\\/\\**";
	charset[2] = "AACCBB";
	charset[3] = "ACACBB";
	charset[4] = "ACCABB";
	return (charset[g_rushn]);
}

void	row(int *coords)
{
	char	*charset;

	charset = get_charset();
	while (*(coords + 2) <= (*coords) - 1)
	{
		if (*(coords + 3) == 0)
			if (*(coords + 2) == 0)
				ft_putchar(charset[0]);
			else if (*(coords + 2) == (*coords) - 1)
				ft_putchar(charset[1]);
			else
				ft_putchar(charset[4]);
		else if (*(coords + 3) == *(coords + 1) - 1)
			if (*(coords + 2) == 0)
				ft_putchar(charset[2]);
			else if (*(coords + 2) == (*coords) - 1)
				ft_putchar(charset[3]);
			else
				ft_putchar(charset[4]);
		else
			if (*(coords + 2) == 0 || *(coords + 2) == *(coords) - 1)
				ft_putchar(charset[5]);
			else
				ft_putchar(' ');
		(*(coords + 2))++;
	}
}

void	rush(int x, int y)
{
	int	x1;
	int	y1;
	int	coords[4];

	if (x > 0 && y > 0)
	{
		coords[0] = x;
		coords[1] = y;
		x1 = 0;
		y1 = 0;
		while (y1 <= y - 1)
		{
			coords[2] = x1;
			coords[3] = y1;
			row(coords);
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
