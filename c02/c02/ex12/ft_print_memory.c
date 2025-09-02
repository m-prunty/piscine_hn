/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:16:06 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/12 16:10:08 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*res;

	res = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

void	ft_puthex(char nb)
{
	char	hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	if (nb > 15)
	{	
		ft_puthex(nb / 16);
		ft_putchar(hex[(int)nb % 16]);
	}
	else
		ft_putchar(hex[(int)nb]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	while (size--)
	{
		ft_puthex(((char *)addr)[0]);
		addr++;
	}
	return (addr);
}
/*
#include <stdio.h>
int	main()
uasgf{
	char *str = "uasgfudgjg";

	ft_print_memory(str, 10);
	ft_putchar('\n');
	printf("%p\n",str);
} 
*/
