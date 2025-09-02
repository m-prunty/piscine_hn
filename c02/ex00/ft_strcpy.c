/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:04 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/12 15:06:42 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*res;

	res = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hello";
	char	src0[] = "";
	char	src1[] = "Hello\nspecial\t\tchar\vtest";
	char	dest[10] = "aaaaaaaaa";	

	printf("init dest:\n\t %s\n", dest);
	printf("null:\n\t %s\n", ft_strcpy(dest, src0));
	printf("spec char:\n\t %s\n", ft_strcpy(dest, src1));
	printf("basic:\n\t %s\n", ft_strcpy(dest, src));
	printf("same buff:\n\t %s\n", ft_strcpy(dest, dest));
//	printf("overlap:\n\t %s\n", ft_strcpy(dest + 2, dest) + 2 );
	printf("overlap:\n\t %s\n", strcpy(dest + 2, dest) + 2 );

}
*/
