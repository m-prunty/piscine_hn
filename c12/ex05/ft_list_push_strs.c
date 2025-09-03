/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:46:15 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:39:22 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*lst;

	lst = NULL;
	while (size-- && *strs)
		ft_list_push_front(&lst, *strs++);
	return (lst);
}
