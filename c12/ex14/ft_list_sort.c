/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:05:06 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:46:11 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

int	ft_list_issorted(t_list *begin_list, int (*cmp)(char *, char *), int dir)
{
	if (begin_list->data && begin_list->next)
	{
		if (dir >= 0)
		{
			if (cmp(begin_list->data, begin_list->next->data) <= 0)
				return (1 * ft_list_issorted(begin_list->next, *cmp, dir));
		}
		else
		{
			if (cmp(begin_list->data, begin_list->next->data) >= 0)
				return (1 * ft_list_issorted(begin_list->next, *cmp, dir));
		}
		return (0);
	}
	return (1);
}

void	ft_list_sort_cmprec(t_list **begin_list, int (*cmp)(char *, char *))
{
	if ((*begin_list)->data && (*begin_list)->next)
	{
		ft_list_sort_cmprec(&(*begin_list)->next, cmp);
		if (cmp((*begin_list)->data, (*begin_list)->next->data) >= 0)
			ft_list_swap(begin_list, 0, 1);
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(char *, char *))
{
	while (!ft_list_issorted(*begin_list, cmp, 1))
		ft_list_sort_cmprec(begin_list, cmp);
}
