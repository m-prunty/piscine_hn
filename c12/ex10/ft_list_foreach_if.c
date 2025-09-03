/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:03:15 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:42:28 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
						void *data_ref, int (*cmp)(char *, char *))
{
	if (begin_list && begin_list->data)
	{
		if (!cmp(begin_list->data, data_ref))
			f(begin_list->data);
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
	}
}
