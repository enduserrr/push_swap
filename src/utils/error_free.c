/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:27:07 by asalo             #+#    #+#             */
/*   Updated: 2024/02/28 09:21:01 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *strn)
{
	if (!(*strn == '+' || *strn == '-' || (*strn >= '0' && *strn <= '9')))
		return (1);
	if ((*strn == '+' || *strn == '-') && !(strn[1] >= '0' && strn[1] <= '9'))
		return (1);
	while (*++strn)
	{
		if (!(*strn >= '0' && *strn <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
