/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:07:30 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:48:47 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;

	if (ft_list_issorted(*begin_list, cmp, 1))
	{
		tmp = (ft_list_find_prev(*begin_list, data, cmp));
		ft_list_insert(&tmp, ft_create_elem(data), 1);
	}
}
