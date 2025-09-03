/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:58:26 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:41:23 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	int	n;
	int	i;

	i = -1;
	n = ft_list_size(*begin_list);
	while (*begin_list && ++i < --n)
		ft_list_swap(begin_list, i, n);
}
