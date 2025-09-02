/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 04:01:33 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 21:20:00 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_isvalid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(base);
	if (len > 1)
	{
		while (base[++i])
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			else
			{
				j = -1;
				while (++j < i)
					if (base[j] == base[i])
						return (0);
			}
		}
		return (i);
	}
	return (0);
}

int	ft_convert_charbase(char c, int *val, char *base)
{
	*val = 0;
	while (base[*val])
	{
		if (c == base[*val])
			return (*val);
		(*val)++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	neg;
	int	base_len;
	int	val;

	base_len = ft_isvalid_base(base);
	val = 0;
	res = 0;
	neg = 1;
	if (base_len)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		while (*str == '-' || *str == '+')
			if (*str++ == '-')
				neg *= -1;
		while (*str)
		{
			if (ft_convert_charbase(*str++, &val, base) >= 0)
				res = res * base_len + val;
			else
				break ;
		}
	}
	return (res * neg);
}

void	ft_putchar_str(char c, char *str)
{
	//str;
	//while (*++str)
	//	;
	*++str = c;
	*str = '\0';
}

void	ft_putnbr_base_s(int nbr, char *base, char **str)
{
	long	lnb;
	int		base_len;

	base_len = ft_isvalid_base(base);
	if (base_len)
	{
		if (nbr == 1 << 31)
		{
			lnb = ~(long)(1 << 31) + 1;
			ft_putnbr_base_s(-lnb / base_len, base, str);
			ft_putchar_str(base[lnb % base_len], *str);
		}
		else if (nbr < 0)
		{
			ft_putchar_str('-', *str);
			ft_putnbr_base_s(-nbr, base, str);
		}
		else if (nbr >= base_len)
			ft_putnbr_base_s(nbr / base_len, base, str);
		ft_putchar_str(base[nbr % base_len], *str);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		decimal;
	char 	*s;

	str = (char *)malloc(sizeof(char *) * 32);
	s = str;
	if (ft_isvalid_base(base_from) && ft_isvalid_base(base_to))
	{
		decimal = ft_atoi_base(nbr, base_from);
		ft_putnbr_base_s(decimal, base_to, &str);
		return (s);
	}
	return (NULL);
}
