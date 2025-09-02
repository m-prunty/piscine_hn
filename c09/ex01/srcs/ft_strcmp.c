/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:56:40 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/13 23:53:12 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char	*str = "abcd" ;
	char	*str1 = "bcd" ;
	char	*str2 = "abc" ;
	char	*str3 = "";
	char	*str4 = "abxd";

	printf("%i v %i \n", ft_strcmp(str, str2), strcmp(str, str2));
	printf("%i v %i \n", ft_strcmp(str + 1, str1), strcmp(str + 1, str1));
	printf("%i v %i \n", ft_strcmp(str, str3), strcmp(str, str3));
	printf("%i v %i \n", ft_strcmp(str3, str), strcmp(str3, str));
	printf("%i v %i \n", ft_strcmp(str, str4), strcmp(str, str4));
}
*/
