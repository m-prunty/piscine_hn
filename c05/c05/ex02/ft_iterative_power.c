/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:08:55 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/19 14:20:53 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power > 0)
	{
		while (--power > 0)
			nb *= n;
		return (nb);
	}
	else if (power < 0)
		return (0);
	else
		return (1);
}
/*
   int	main()
   {
   ft_iterative_power(-2, 3);

   }
 */
