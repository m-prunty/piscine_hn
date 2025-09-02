/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 05:29:25 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/06 15:42:32 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_pow(int	n)
{
	int res;

	res = 1;
	while (n-- > 0)
		res *= 10;
	return (res) ;
}

int	endtest(int dig, char *str)
{
	int	n;
	int	res;
	int pow;

	n = 0;
	res = 0;
	while (dig--)
	{
		pow = ft_pow(dig);
		n += (10 - (dig + 1)) * pow;
		res += ((*str++) - 48) * pow;
	}
	return (res - n);
}

void	comb(int start, int dig, int n, char *str)
{
	int	 i;

	if (n == 0)
	{
		write(1, str, dig);
		if (endtest(dig, str)  )
			write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		str[dig - n] = i + 48;
		comb(i + 1, dig, n - 1, str);
		i++;
	}
} 

void	ft_print_combn(int n)
{
	char	str[11];
	int	i;

	i = 0;
	while (i < n)
		str[i++] = 0;
	if (n >= 1 && n <= 10)
		comb(0, n, n, str);
}
/*
int main()
{
	write(1, "\nex08:\n\t",8);
	ft_print_combn(3);
	ft_print_combn(4);
	ft_print_combn(1);
	ft_print_combn(10);
}
*/
