/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:04 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/19 02:24:35 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_strncpy(char *dest, char *src, int n)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hello";
	char	src1[] = "Hello";
	//	char	src0[] = "";
	//	char	src1[] = "Hello\nspecial\t\tchar\vtest";

	char	dest[20];
	char	dest1[20];

	printf("basic:\n\t |%p|%p|%p|\n", ft_strncpy(dest, src, 2), dest, src);
	printf("basic:\n\t |%p|%p|%p|\n", strncpy(dest1, src1, 2), dest, src);
}
*/
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
char	src[] = "Hello";
char	src0[] = "";
char	src1[] = "Hello\nspecial\t\tchar\vtest";
char	dest[10] = "aaaaaaaaa";	
int		n = 3;
int		n1 = 7;

printf("init dest:\n\t %s\n", dest);
printf("null:\t\t%s\nog:\t\t\t%s\n ",
ft_strncpy(dest, src0, n), strncpy(dest, src0, n));
printf("spec char:\n\t %s\n", 
ft_strncpy(dest, src1, n1), strncpy(dest, src0, n));
printf("basic:\n\t %s\n", ft_strncpy(dest, src, n));
printf("same buff:\n\t %s\n", ft_strncpy(dest, dest, 6));
printf("overlap:\n\t %s\n", ft_strncpy(dest + 2, dest, n) + 2 );
printf("overlap:\n\t %s\n", strncpy(dest + 2, dest, n) + 2 );
}
 */
