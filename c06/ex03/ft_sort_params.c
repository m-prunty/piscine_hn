/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:41:03 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/18 19:46:59 by maprunty         ###   ########.fr       */
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

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	**args;

	i = 0;
	if (ac >= 2)
	{
		args = av;
		while (args[++i] && i + 1 < ac)
		{
			if (ft_strcmp(args[i], args[i + 1]) > 0)
			{
				ft_swap(&args[i], &args[i + 1]);
				i = 0;
			}
		}
		i = 0;
		while (args[++i])
		{
			ft_putstr(args[i]);
			ft_putchar('\n');
		}
	}
	return (0);
}
