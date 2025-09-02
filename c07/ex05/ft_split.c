/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 05:08:03 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 22:41:24 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, int n)
{
	char	*res;

	res = dest;
	while (*src && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

char	*ft_strndup(char *src, int n)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * n);
	ft_strncpy(res, src, n);
	return (res);
}

int	in_charset(char s, char *charset)
{
	--charset;
	while (*++charset)
		if (*charset == s)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str && *charset)
	{
		while (in_charset(*str, charset))
			str++;
		if (*str)
			count++;
		while (!in_charset(*str, charset) && *str)
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		n;
	int		i;
	int		j;

	i = -1;
	n = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * n);
	if (!charset)
		*res = str;
	else
	{
		while (*str)
		{
			while (in_charset(*str, charset))
				str++;
			if (*str)
				i++;
			j = 0;
			while (!in_charset(*str, charset) && *str && ++j)
				str++;
			if (i < n && !res[i])
				res[i] = ft_strndup((str - j), j);
		}
	}
	return (res);
}

/*
#include <stdio.h>
int main()
{
char *str = "     sadaf qweq    qweqwe    w";
char *str1 = "i     sadaf   qweq    qweqwe    ";
char **s;
char **s1;

s = ft_split(str, " ");
s1 = ft_split(str1, " ");
//printf("%i", count_words(str, " "));
//printf("%i", count_words(str1, " "));

}*/

