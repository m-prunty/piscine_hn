/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:26:28 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 17:21:32 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sorted(int *tab, int size)
{
	while (--size)
	{
		if (!(*tab <= *(tab + 1)))
			return (0);
		tab++;
	}
	return (1);
}

void	bubble(int *tab, int size)
{
	int	*i;
	int	s2;

	i = tab;
	s2 = size;
	while (--size)
	{
		if (*tab >= *(tab + 1))
			ft_swap(tab, (tab + 1));
		tab++;
	}
	if (!(is_sorted(i, s2)))
		bubble(i, s2);
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (!size || is_sorted(tab, size))
		return ;
	bubble(tab, size);
}

/*
#include <stdio.h>
void	print_int_arr(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("%d", arr[i]);
	printf("\n");
}

int main()
{
	int	arr[] = {9,8,7,6,5,4,3,2,1,1};
	int	arr0[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int	arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int arr3[] = {7, 6, 3, 4, 2, 5};
	int arr4[] = {-7, -6,-3, -4, -2, -5};
	int arr5[] = {3, 1, 2, 3, 1, 2};
	int arr6[] = {42};
	int arr7[] = {};
	int	len = 10;
	int len0 = 6;
	//printf("---->%d\n", is_sorted(arr, len));
	ft_sort_int_tab(arr, len);
	print_int_arr(arr, len);
	
	ft_sort_int_tab(arr0, len);
	print_int_arr(arr0, len);
	
	ft_sort_int_tab(arr1, len);
	print_int_arr(arr1, len);
	
	ft_sort_int_tab(arr2, len);
	print_int_arr(arr2, len);
	
	ft_sort_int_tab(arr3, len0);
	print_int_arr(arr3, len0);
	
	ft_sort_int_tab(arr4, len0);
	print_int_arr(arr4, len0);
	
	ft_sort_int_tab(arr5, len0);
	print_int_arr(arr5, len0);
	
	ft_sort_int_tab(arr6, 1 );
	print_int_arr(arr6, 1);
	
	ft_sort_int_tab(arr7, 0);
	print_int_arr(arr7, 0);
}
*/	
