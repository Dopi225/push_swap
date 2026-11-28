/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:52:37 by marigal           #+#    #+#             */
/*   Updated: 2026/11/28 04:24:26 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	handle_exit(char *src, t_ctx *c)
{
	free(src);
	error_exit(c);
}

static void	check(char *src, int size, t_ctx *c)
{
	if (ft_strncmp(src, "pa", size) == 0)
		pa_checker(c);
	else if (ft_strncmp(src, "pb", size) == 0)
		pb_checker(c);
	else if (ft_strncmp(src, "sa", size) == 0)
		sa_checker(c);
	else if (ft_strncmp(src, "sb", size) == 0)
		sb_checker(c);
	else if (ft_strncmp(src, "ss", size) == 0)
		ss_checker(c);
	else if (ft_strncmp(src, "ra", size) == 0)
		ra_checker(c);
	else if (ft_strncmp(src, "rb", size) == 0)
		rb_checker(c);
	else if (ft_strncmp(src, "rr", size) == 0)
		rr_checker(c);
	else if (ft_strncmp(src, "rra", size) == 0)
		rra_checker(c);
	else if (ft_strncmp(src, "rrb", size) == 0)
		rrb_checker(c);
	else if (ft_strncmp(src, "rrr", size) == 0)
		rrr_checker(c);
	else
		handle_exit(src, c);
}

static void	executioner(char *instruction, t_ctx *c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (instruction[i])
	{
		j = i;
		while (instruction[j] && instruction[j] != '\n')
		{
			j++;
		}
		len = j - i;
		check(&instruction[i], len, c);
		i = j + 1;
	}
}

static char	*reader(void)
{
	char	*buff;
	ssize_t	i;
	ssize_t	j;

	buff = NULL;
	i = BUFF_SIZE;
	j = 0;
	while (i > 0)
	{
		buff = ft_realloc(buff, j);
		if (!buff)
			return (NULL);
		i = read(0, (buff + j), BUFF_SIZE);
		j += i;
	}
	buff[j] = '\0';
	return (buff);
}

int	main(int argc, char **argv)
{
	char	*instruction;
	t_ctx	c;

	init_ctx(&c);
	if (!parse_args(&c, argc, argv))
		return (error_exit(&c));
	if (!c.a)
		return (0);
	instruction = reader();
	executioner(instruction, &c);
	c.disorder = compute_disorder(c.a);
	if (c.disorder == 0.0 && stack_size(c.b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&c.a);
	free_stack(&c.b);
	free(instruction);
}
