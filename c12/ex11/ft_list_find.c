/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:03:27 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:43:07 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list	*ft_list_find(t_list *begin_list,
		void *data_ref, int (*cmp)(char *, char *))
{
	if (begin_list && begin_list->data)
	{
		if (cmp(begin_list->data, data_ref))
			return (ft_list_find(begin_list->next, data_ref, cmp));
	}
	return (begin_list);
}
