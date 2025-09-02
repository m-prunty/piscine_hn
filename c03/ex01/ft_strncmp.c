/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:56:40 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/13 23:52:26 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = -1;
	while ((s1[++i] || s2[i]) && n--)
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

	printf("%i v %i \n", ft_strncmp(str, str2, 3), strncmp(str, str2, 3));
	printf("%i v %i \n", ft_strncmp(str + 1, str1, 3), strncmp(str + 1, str1, 3));
	printf("%i v %i \n", ft_strncmp(str, str3, 4), strncmp(str, str3, 4));
	printf("%i v %i \n", ft_strncmp(str3, str, 0), strncmp(str3, str, 0));
	printf("%i v %i \n", ft_strncmp(str, str4, 5), strncmp(str, str4, 5));
}
*/
