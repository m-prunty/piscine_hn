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

#include <stdlib.h>

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
	char	**ptr;
	int		j;

	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	ptr = res;
	if (!str || !res)
		return (NULL);
	else
	{
		while (*str)
		{
			while (in_charset(*str, charset))
				str++;
			j = 0;
			while (!in_charset(*str, charset) && *str && ++j)
				str++;
			*ptr++ = ft_strndup((str - j), j);
		}
	}
	return (res);
}

/*
#include <stdio.h>
int main()
{
char *word = "sadaf";
char *str = "     sadaf qweq    qweqwe    w";
char *str1 = "i     sadaf   qweq    qweqwe    ";
char **s1;
char **s2;
char **s3;
char **s4;
char **s5;

s1 = ft_split("", "");
s2 = ft_split("hello", "");
s3 = ft_split(",,hello,world,,", ",");
s4 = ft_split("hello,,,,world", ",");
s5 = ft_split("aaabbbaaaccc", "ab");
w1 = ft_split(word, "");
s1 = ft_split(str, " ");
s2 = ft_split(str1, " ");
	//printf("%i", count_words(str, " "));
//printf("%i", count_words(str1, " "));
}

*/
