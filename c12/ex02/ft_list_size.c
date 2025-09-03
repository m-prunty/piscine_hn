/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:45:27 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 01:45:43 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list && ++i && begin_list->next)
		begin_list = begin_list->next;
	return (i);
}
