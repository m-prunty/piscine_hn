/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:46:02 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:38:38 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
		ft_list_last(*begin_list)->next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}
