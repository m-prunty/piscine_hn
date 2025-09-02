/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:16:42 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 20:40:43 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = ft_strlen(src);
	while (size--)
		*dest++ = *src++;
	*--dest = '\0';
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joint;
	int		n;
	int		i;
	int		j;

	i = -1;
	j = 0;
	n = ft_strlen(sep) * (size - 1) + 1;
	while (++i < size)
		n += ft_strlen(strs[i]);
	joint = (char *)malloc(sizeof(char) * n);
	i = -1;
	while (++i < size)
	{
		j += ft_strlcpy(joint + j, strs[i], ft_strlen(strs[i]) + 1);
		if (i != size - 1)
			j += ft_strlcpy(joint + j, sep, ft_strlen(sep) + 1);
	}
	return (joint);
}
/*
#include <stdio.h>
int	main()
{
	int		size = 3;
	//char	*strs[] = {"Hello", "world", "!" };
	char	*strs[] = {"", "Hello", "", "world"};
	char	*sep = "-";

	printf("%s", ft_strjoin(size, strs, sep));
}
*/
