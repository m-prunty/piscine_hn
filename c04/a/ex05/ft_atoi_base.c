/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 05:12:41 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/17 19:28:09 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_convert_charbase(char c, int *val, char *base)
{
	*val = 0;
	while (base[*val])
	{
		if (c == base[*val])
			return (*val);
		(*val)++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	neg;
	int	base_len;
	int	val;

	base_len = ft_isvalid_base(base);
	val = 0;
	res = 0;
	neg = 1;
	if (base_len)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		while (*str == '-' || *str == '+')
			if (*str++ == '-')
				neg *= -1;
		while (*str)
		{
			if (ft_convert_charbase(*str++, &val, base) >= 0)
				res = res * base_len + val;
			else
				break ;
		}
	}
	return (res * neg);
}
/*
#include <stdio.h>
#include <unistd.h>
int ft_putchar(char c)
{
	write(1, &c, 1);
}
int	main()
{
	printf("%i\n",ft_atoi_base("12345","001123456789"));
	ft_putchar('\n');
	printf("%i\n",ft_atoi_base("-110002345", "011"));
	ft_putchar('\n');
	printf("%i\n",ft_atoi_base("0", "a"));
	ft_putchar('\n');
	//printf("%i", ~(1<<31));
	//printf("%i", (1<<31), );
	printf("%i\n",ft_atoi_base("10000000000000000000000000000000a", "01"));
	ft_putchar('\n');
	printf("%i\n",ft_atoi_base("0111111111111111111111111111111111a", "01"));
	ft_putchar('\n');
	printf("%i\n",ft_atoi_base("-a","0123456789abcdef"));
	ft_putchar('\n');
}
*/
