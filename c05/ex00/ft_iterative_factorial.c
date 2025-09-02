/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 06:41:22 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/19 14:18:07 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		res = 1;
	while (nb > 1)
		res *= nb--;
	return (res);
}

/*
int	main()
{
	ft_iterative_factorial(10);
	}
	*/
