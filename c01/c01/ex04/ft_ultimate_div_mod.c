/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:57:52 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 16:47:25 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

/*
#include <stdio.h>
int    main(void)
{
     int a;
     int b;

     a = 11;
     b = 2;

     printf("%d %d\n", a, b);
     ft_ultimate_div_mod(&a, &b);
     printf("%d %d\n", a, b);
}
*/
