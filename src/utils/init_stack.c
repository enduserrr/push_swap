/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:10:32 by asalo             #+#    #+#             */
/*   Updated: 2024/02/28 08:25:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	n;
	int		is_neg;
	int		i;

	n = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * is_neg);
}

void	stack_init(t_stack_node **a, char **argv, bool argc_is_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a);
		if (error_repetition(*a, (int)n))
			error_free(a);
		append_node(a, (int)n);
		++i;
	}
	if (argc_is_2)
	{
		i = -1;
		if (NULL == argv || NULL == *argv)
			return ;
		while (argv[i])
			free(argv[i++]);
		free(argv - 1);
	}
}
