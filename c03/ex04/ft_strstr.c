/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:21:29 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/14 14:33:37 by maprunty         ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = -1;
	while ((s1[++i] || s2[i]) && n--)
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = ft_strlen(to_find);
	if (!i)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
			if (!ft_strncmp(str, to_find, i))
				return (str);
		str++;
	}
	return (0);
}
