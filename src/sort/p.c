/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:03:30 by asalo             #+#    #+#             */
/*   Updated: 2024/02/28 09:26:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
