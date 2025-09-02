/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:08:24 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/12 19:15:13 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	char	*res;

	res = str;
	while (*str)
	{
		if (ft_is_lower(*str))
			*str -= 32;
		str++;
	}
	return (res);
}
