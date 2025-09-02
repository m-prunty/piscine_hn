/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 05:16:48 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/20 19:15:24 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(n) (n % 2 == 0)
# define TRUE 1 
# define FALSE 0
# define ODD_MSG "I have an even number of arguments."
# define EVEN_MSG "I have an odd number of arguments."
# define SUCCESS 0

typedef int	t_bool;

#endif
