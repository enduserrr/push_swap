/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:15:55 by asalo             #+#    #+#             */
/*   Updated: 2024/02/28 11:30:41 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../push_swap/incs/push_swap.h"
# include <fcntl.h>

void	check_command(t_stack_node **a, t_stack_node **b, char *command);
void	error(t_stack_node **a, t_stack_node **b);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2, int *line_end);
char	*get_next_line(int fd);

#endif