/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:18:24 by asalo             #+#    #+#             */
/*   Updated: 2024/02/26 13:10:29 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node, bool checker)
{
	if (checker == true)
	{
		while (*a != cheapest_node->target_node
			&& *b != cheapest_node)
			rr(a, b, false);
		set_current_position(*a);
		set_current_position(*b);
	}
	else
	{
		while (*a != cheapest_node->target_node
			&& *b != cheapest_node)
			rrr(a, b, false);
		set_current_position(*a);
		set_current_position(*b);
	}
}

void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node, true);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node, false);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len == 5)
		handle_five(a, b);
	else
	{
		while (a_len-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	if (find_smallest(*a)->above_median)
		while ((*a)->value != find_smallest(*a)->value)
			ra(a, false);
	else
		while ((*a)->value != find_smallest(*a)->value)
			rra(a, false);
}
