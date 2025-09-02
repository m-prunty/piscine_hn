/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:08:24 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/12 23:32:22 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_spec(char c)
{
	if (!ft_is_lower(c) && !ft_is_upper(c) && !ft_is_num(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*res;

	res = str;
	if (ft_is_lower(*str))
		*str += -32;
	while (*++str)
	{
		if (ft_is_spec(*(str - 1)) && ft_is_lower(*str))
			*str += -32;
		else if (!ft_is_spec(*(str - 1)) && ft_is_upper(*str))
			*str += 32;
	}
	return (res);
}

/*
#include <stdio.h>
int	main()
{	
	char src[]="hi, how are you? 42words forty-two; fifty+and+one";
	char src1[]="   hi, how are you? 42words forty-two;
	 \tfifty+and+one +++----    kjhskjdhfkj";
	char src2[]="zhi,z zhow are you?z 42 words forty - two;asd fifty+and+one";
	ft_strcapitalize(src);
	printf("%s\n", src);
	ft_strcapitalize(src1);
	printf("%s\n", src1);
	ft_strcapitalize(src2);
	printf("%s\n", src2);

}
*/
