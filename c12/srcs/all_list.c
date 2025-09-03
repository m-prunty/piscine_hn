
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:03:38 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:55:06 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->next = NULL;
	lst->data = data;
	return (lst);
}
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*ele;

	ele = ft_create_elem(data);
	if (begin_list && *begin_list)
		ele->next = *begin_list;
	*begin_list = ele;
}
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

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list && ++i && begin_list->next)
		begin_list = begin_list->next;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:45:50 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:38:29 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
		ft_list_last(*begin_list)->next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*lst;

	lst = NULL;
	while (size-- && *strs)
		ft_list_push_front(&lst, *strs++);
	return (lst);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:47:10 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:40:42 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
		++i;
	}
	return (begin_list);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:58:26 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:41:23 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	int	n;
	int	i;

	i = -1;
	n = ft_list_size(*begin_list);
	while (*begin_list && ++i < --n)
		ft_list_swap(begin_list, i, n);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:01:51 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:41:50 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list && begin_list->data)
		f((begin_list)->data);
	if (begin_list)
		ft_list_foreach(begin_list->next, f);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:04:35 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:45:11 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	ft_list_last(*begin_list1)->next = begin_list2;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:05:06 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:46:11 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_list_issorted(t_list *begin_list, int (*cmp)(char *, char *), int dir)
{
	if (begin_list->data && begin_list->next)
	{
		if (dir >= 0)
		{
			if (cmp(begin_list->data, begin_list->next->data) <= 0)
				return (1 * ft_list_issorted(begin_list->next, *cmp, dir));
		}
		else
		{
			if (cmp(begin_list->data, begin_list->next->data) >= 0)
				return (1 * ft_list_issorted(begin_list->next, *cmp, dir));
		}
		return (0);
	}
	return (1);
}

void	ft_list_sort_cmprec(t_list **begin_list, int (*cmp)(char *, char *))
{
	if ((*begin_list)->data && (*begin_list)->next)
	{
		ft_list_sort_cmprec(&(*begin_list)->next, cmp);
		if (cmp((*begin_list)->data, (*begin_list)->next->data) >= 0)
			ft_list_swap(begin_list, 0, 1);
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(char *, char *))
{
	while (!ft_list_issorted(*begin_list, cmp, 1))
		ft_list_sort_cmprec(begin_list, cmp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:07:01 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:47:46 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:07:30 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:48:47 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;

	if (ft_list_issorted(*begin_list, cmp, 1))
	{
		tmp = (ft_list_find_prev(*begin_list, data, cmp));
		ft_list_insert(&tmp, ft_create_elem(data), 1);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:09:09 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/03 02:50:21 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sorted_list_merge(t_list **begin_list1,
					t_list *begin_list2, int (*cmp)())
{
	t_list	*tmp;

	if (begin_list2)
	{
		tmp = ft_list_at(begin_list2, 0);
		ft_list_rm(&begin_list2, 0);
		ft_sorted_list_merge(begin_list1, begin_list2, cmp);
		ft_sorted_list_insert_ele(begin_list1, tmp, cmp);
	}
}
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
