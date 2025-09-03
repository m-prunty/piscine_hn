/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:09:09 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:50:21 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
					t_list *begin_list2, int (*cmp)())
{
	t_list	*tmp;

	if (begin_list2)
	{
		tmp = ft_list_at(begin_list2, 0);
		ft_list_rm(&begin_list2, 0);
		ft_sorted_list_merge(begin_list1, begin_list2, cmp);
		ft_sorted_list_insert_ele(begin_list1, tmp, cmp);
	}
}
