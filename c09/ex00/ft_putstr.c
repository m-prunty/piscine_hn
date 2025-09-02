/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:32:20 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/12 21:31:40 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

#include <stdio.h>
int main()
{
	char *str = "abcdef";

	printf("%s, %p\n", str, str);
	str++;
	printf("%s, %p\n", str, str);
	printf("%s, %p\n", str + 1, str + 1);
	printf("%s, %p\n", str, str);
	}
