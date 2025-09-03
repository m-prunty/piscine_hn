/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:12:40 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:13:55 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

int	main()
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst3;
	char *strs[] = {"F", "E" , "D"};
	char *strs2[] = {"1", "3" , "4", "4", "5"};
	char *strs3[] = {"6", "5", "4", "2", "1"};

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	ft_putnbr(ft_list_size(lst));
	ft_putstr(ft_list_last(lst)->data);
	ft_list_push_back(&lst, "C");
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);
	ft_putstr("\n");

	lst2 = ft_list_push_strs(3, strs);
	ft_putnbr(ft_list_size(lst2));
	ft_putstr(ft_list_last(lst2)->data);
	ft_putstr("\n-->");
	ft_list_foreach(lst2, ft_putstrv);
	ft_putstr("\n");
	ft_list_clear(lst, free_fct);
	ft_putstr(ft_list_at(lst2, 1)->data);
	ft_putstr("\n-->");
	lst = NULL;
	ft_list_foreach(lst, ft_putstrv);

	lst = ft_list_push_strs(5, strs2);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);
	ft_putstr("\nsrt-->");
	ft_putnbr(ft_list_issorted(lst, ft_strcmp, 1));
	/*
	ft_list_reverse(&lst);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);
	ft_putstr("\nsrt-->");
	ft_putnbr(ft_list_issorted(lst, ft_strcmp, 1));
	*/
	ft_putstr("\nif-->");
	ft_list_foreach_if(lst, ft_putstrv, "4", ft_strcmp);


	ft_list_remove_if(&lst, "4", ft_strcmp, free_fct2);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);

	ft_list_merge(&lst, lst2);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);
	ft_putstr("\nsrt-->");
	ft_putnbr(ft_list_issorted(lst, ft_strcmp, 1));

	ft_list_sort(&lst, ft_strcmp);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);

	ft_sorted_list_insert(&lst, "4", ft_strcmp);
	ft_putstr("\nins-->");
	ft_list_foreach(lst, ft_putstrv);

	lst3 = ft_list_push_strs(5, strs3);
	ft_sorted_list_merge(&lst,lst3, ft_strcmp);
	ft_putstr("\nsrtm-->");
	ft_list_foreach(lst, ft_putstrv);

}

