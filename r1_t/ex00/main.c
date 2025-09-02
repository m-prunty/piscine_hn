/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraimann <eraimann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:22:21 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/10 16:17:19 by eraimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
void	get_clues(int n, int *clues, char **av)

{
	int	i;

	i = 0;
	while (i < n * 4)
	{
		clues[i++] = (**av) - 48;
		*av += 2;
	}	
	clues[i] = 0;
}

void	init_board(int n, int *board)
{
	int	i;

	i = 0;
	while (i < n * n)
		board[i++] = 0;
	board[i] = -1;
}

void	print_board(int n, int *board)
{
	int	i;

	i = 0;
	while (i < n * n)
	{
		ft_putchar(board[i] + 48);
		ft_putchar(' ');
		i++;
		if (!(i % n))
			ft_putchar('\n');
	}
}

void	set_location(int *board, int i, int val)
{
	board[i] = val;
}

void	init_values(int n, int *clues, int *board)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (clues[i] == n)
			board[i] = 1;
		else if (clues[i] == 1)
			board[i] = n;
		if (clues[n + i] == n)
			board[n * n - n + i] = 1;
		else if (clues[n + i] == 1)
			board[n * n - n + i] = n;
		if (clues[((n * n) / 2) + i] == n)
			board[n * (i % n)] = 1;
		else if (clues[((n * n) / 2) + i] == 1)
			board[n * (i % n)] = n;
		if (clues[((n * n) / 2) + n + i] == n)
			board[n * (i % n) + n - 1] = 1;
		else if (clues[((n * n) / 2) + n + i] == 1)
			board[n * (i % n ) + n - 1] = n;
		i++;
	}
}

int main(int ac, char **av)
{
	int	n;
	int	board[100];
	int	clues[40];

	n = 4;
	get_clues( n, clues, ++av);
	init_board(n, board);
	init_values(n, clues, board);
	print_board (n , board);
}
