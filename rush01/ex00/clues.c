/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:40:50 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/11 00:41:44 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_clues(int n, int *clues, char **av)
{
	int		i;
	char	c;

	i = 0;
	while (i < n * 4)
	{
		c = **av;
		if (!(c >= '0' && c <= '9'))
		{
			write(1, "Error: Not INT\n", 16);
			return (0);
		}
		clues[i++] = (**av) - 48;
		*av += 2;
	}	
	clues[i] = 0;
	return (1);
}

void	fill_one_to_n(int n, int loc, int dir, int *board)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (dir == 1)
			board[loc + i * n] = i + 1;
		else if (dir == -1)
			board[loc - i * n] = i + 1;
		else if (dir == 2)
			board[loc++] = i + 1;
		else if (dir == -2)
			board[loc--] = i + 1;
	}
}

void	cluen_one(int n, int *clues, int *board)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (clues[i] == n - 1)
			board[n * n - 2 * n + i] = n;
		if (clues[n + i] == n - 1)
			board[n + i] = n;
		if (clues[(2 * n) + i] == n - 1)
			board[n * (i % n) + n - 2] = n;
		if (clues[(2 * n) + n + i] == n - 1)
			board[n * (i % n) + n + 1] = n;
	}
}

void	init_clues(int n, int *clues, int *board)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (clues[i] == n)
			fill_one_to_n(n, i, 1, board);
		else if (clues[i] == 1)
			board[i] = n;
		if (clues[n + i] == n)
			fill_one_to_n(n, n * n - n + i, -1, board);
		else if (clues[n + i] == 1)
			board[n * n - n + i] = n;
		if (clues[((2 * n)) + i] == n)
			fill_one_to_n(n, n * (i % n), 2, board);
		else if (clues[((2 * n)) + i] == 1)
			board[n * (i % n)] = n;
		if (clues[((2 * n)) + n + i] == n)
			fill_one_to_n(n, n * (i % n) + n - 1, -2, board);
		else if (clues[((2 * n)) + n + i] == 1)
			board[n * (i % n) + n - 1] = n;
		i++;
	}
}
