/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:53:37 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/14 18:33:23 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (*str)
		while (str[++i])
			;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < size && dest[i])
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
char	*src = "Born to code";
char	dest[20] =  "1337 42";
char	*src1 = "Born to code";
char	dest1[20] =  "1337 42";

printf("%i \n", ft_strlcat(dest, src, 20));
printf("%i \n", strlcat(dest1, src1, 20));
}
 */
