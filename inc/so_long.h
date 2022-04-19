/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:14:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 18:22:40 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>

typedef struct	s_data {
	void 	*img;
	char 	*addr;
	int 	bbp;
	int		line_length;
	int 	endian;
}				t_data;

#endif