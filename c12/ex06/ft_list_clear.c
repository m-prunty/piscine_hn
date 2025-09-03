/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:46:28 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:40:15 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list && begin_list->next)
	{
		next = begin_list->next;
		free_fct(begin_list);
		free(begin_list);
		begin_list = NULL;
		begin_list = next;
	}
}
