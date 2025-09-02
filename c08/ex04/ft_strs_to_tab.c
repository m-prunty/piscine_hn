/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 06:35:15 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 21:59:02 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
}	t_stock_str;
*/

char	*ft_strcpy(char *dest, char *src)
{
	char	*res;

	res = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		n;

	n = ft_strlen(src);
	res = (char *)malloc(sizeof(char) * n);
	ft_strcpy(res, src);
	return (res);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ss;
	int			i;

	i = 0;
	ss = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ss)
		return (0);
	while (i < ac)
	{
		ss[i].size = ft_strlen(av[i]);
		ss[i].str = av[i];
		ss[i].copy = ft_strdup(av[i]);
		if (!ss[i].copy)
			return (0);
		i++;
	}
	ss[ac].str = 0;
	return (ss);
}

/*
int	main(int ac, char **av)
{
	ft_strs_to_tab(ac, av);
}
*/
