/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:52:30 by marigal           #+#    #+#             */
/*   Updated: 2026/11/24 15:59:29 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 10
# include "../includes/push_swap.h"

void	*ft_realloc(char *pointer, int curr_size);
void	pa_checker(t_ctx *c);
void	pb_checker(t_ctx *c);
void	sa_checker(t_ctx *c);
void	sb_checker(t_ctx *c);
void	ss_checker(t_ctx *c);
void	ra_checker(t_ctx *c);
void	rb_checker(t_ctx *c);
void	rr_checker(t_ctx *c);
void	rra_checker(t_ctx *c);
void	rrb_checker(t_ctx *c);
void	rrr_checker(t_ctx *c);

#endif
