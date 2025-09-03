/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:35:57 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:37:48 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*ele;

	ele = ft_create_elem(data);
	if (begin_list && *begin_list)
		ele->next = *begin_list;
	*begin_list = ele;
}
