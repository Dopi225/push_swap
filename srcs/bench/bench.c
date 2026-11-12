/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:43:06 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 09:07:34 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_disorder(double d)
{
	int	pct;

	pct = (int)(d * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	write(2, ".", 1);
	if (pct % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(pct % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_label_strategy(t_ctx *c)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)c->name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)c->cplx, 2);
	write(2, "\n", 1);
}

void	print_counts(t_ctx *c, int from, int to)
{
	ft_putstr_fd("[bench]", 2);
	while (from <= to)
	{
		write(2, " ", 1);
		ft_putstr_fd((char *)c->op_names[from], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(c->count[from], 2);
		from++;
	}
	write(2, "\n", 1);
}

void	print_bench(t_ctx *c)
{
	print_disorder(c->disorder);
	print_label_strategy(c);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(c->total, 2);
	write(2, "\n", 1);
	print_counts(c, SA, PB);
	print_counts(c, RA, RRR);
}
