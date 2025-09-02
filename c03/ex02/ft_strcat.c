/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:53:37 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 02:17:43 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*res;

	res = dest;
	while (*dest++)
		;
	while (*src)
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
