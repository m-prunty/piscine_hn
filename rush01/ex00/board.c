/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:28:27 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/10 23:43:50 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
