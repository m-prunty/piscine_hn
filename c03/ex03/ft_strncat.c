/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:53:37 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/14 01:19:27 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*res;

	res = dest;
	while (*dest++)
		;
	dest--;
	while (*src && nb--)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

/*
#include <stdio.h>
#include <stdio.h>
int	main()
{
	char	*src;
	char	*src1;
	char	dest[20] = "42  ";

	src = " hello";
	printf("%s v %s \n", ft_strcat(dest, src), strcat(dest, src));
}
*/
