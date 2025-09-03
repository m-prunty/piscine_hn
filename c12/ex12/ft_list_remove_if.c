/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:03:50 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:44:44 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
				int (*cmp)(char *, char *), void (*free_fct)(void *))
{
	t_list	*nele;

	nele = (*begin_list)->next;
	if ((*begin_list) && nele)
	{
		if (!cmp(nele->data, data_ref))
		{
			ft_list_rm((begin_list), 1);
			free_fct(nele->data);
			free(nele);
		}
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
	}
}
