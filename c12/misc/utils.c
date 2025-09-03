/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:10:52 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:11:21 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list *ft_list_find_prev(t_list *begin_list,
					 void *data_ref, int (*cmp)(char *, char *))
{
	if (begin_list->next && begin_list->next->data)
	{
		if (cmp(begin_list->next->data, data_ref) <= 0)
			return (ft_list_find_prev(begin_list->next, data_ref, cmp));
	}
	return (begin_list);
}

void ft_sorted_list_insert_ele(t_list **begin_list, t_list *data, int (*cmp)())
{
	t_list	*tmp;

	{
		tmp = (ft_list_find_prev(*begin_list, data->data, cmp));
		ft_list_insert(
				&tmp,
				data, 
				1 
		);
	}	
}

void ft_list_rm(t_list **begin_list, int pos)
{
	t_list	*p;
	t_list	*n;

	p = ft_list_at(*begin_list, pos - 1);
	n = ft_list_at(*begin_list, pos + 1);
	if (p)
	{
		if (n)
			p->next = n;
		else
			p->next = NULL;
	}
	else
		*begin_list = n;
}

void ft_list_rm_last(t_list **begin_list, int n)
{
	ft_list_at(*begin_list, n - 1)->next = NULL;//ft_list_at(*begin_list, pos + 1);
}

void ft_list_add_back(t_list **begin_list, t_list *ele)
{
	ft_list_last(*begin_list)->next = ele;
}

void ft_list_add_front(t_list **begin_list, t_list *ele)
{
	if (begin_list && *begin_list)
		ele->next = *begin_list;
	*begin_list = ele;
}


void ft_list_reverse_rec(t_list **begin_list, unsigned int n)
{
	if (*begin_list && n != 0)
	{
		ft_list_reverse_rec(begin_list, n);
		ft_list_reverse_rec(begin_list, --n);
	}
}

void	ft_list_insert(t_list **begin_list, t_list *ele, int pos )
{
	t_list	*curr;
	t_list	*prev;

	curr = ft_list_at(*begin_list, pos);
	prev = ft_list_at(*begin_list, pos - 1); 
	if (curr)
		ele->next = curr;
	else
		ele->next = NULL;
	if (prev)
		prev->next =  ele;
	else
		*begin_list = ele;
}

void	ft_list_swap(t_list **begin_list, int a, int b)
{
	t_list	*elea;
	t_list	*eleb;
	/*
	 * t_list	*eleaprev;
	t_list	*elebprev;
	*/
	int	n;

	n  = ft_list_size(*begin_list);
	if (n > 1 && a < b)
	{
		elea = ft_list_at(*begin_list, a);
		eleb = ft_list_at(*begin_list, b);
		ft_list_rm(begin_list, b );
		ft_list_insert(begin_list, eleb, a);
		ft_list_rm(begin_list, a + 1);
		ft_list_insert(begin_list, elea, b);
	}
}


/*
void ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*rev_list;
	int		n;
	int		i;


	n = ft_list_size(*begin_list);
while (i++ < n)
{
	tmp = ft_list_last(*begin_list);
	ft_list_add_back(&rev_list, `tmp);
	ft_list_rm(&begin_list, n - i);
}
	//ft_list_at(*begin_list, );
}
*/

void	ft_putstrv(void *str)
{
	ft_putstr((char *)str);
}

void free_fct(void *t)
{
	t_list	*lst;
	
	lst = (t_list *)t;
	lst->data = NULL;
	lst->next = NULL;
	lst	= NULL;
	return ;
}

int ft_list_is(t_list **begin_list)
{
	if (*begin_list && (*begin_list)->data)
		return (1);
	return (0);
}
/*
void free_fct2(void *data)
{
	data = NULL;
	return ;
}
*/

/*

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
*/
	/*
	ft_list_reverse(&lst);
	ft_putstr("\n-->");
	ft_list_foreach(lst, ft_putstrv);
	ft_putstr("\nsrt-->");
	ft_putnbr(ft_list_issorted(lst, ft_strcmp, 1));
	*/
	/*
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

*/
