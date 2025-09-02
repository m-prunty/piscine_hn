/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:08:24 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 22:22:37 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_upper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (ft_is_lower(*str) || ft_is_upper(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
