/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:04:02 by asalo             #+#    #+#             */
/*   Updated: 2024/03/02 10:46:18 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char sep)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*str)
	{
		if (*str != sep && inside_word == false)
		{
			inside_word = true;
			count++;
		}
		else if (*str == sep)
			inside_word = false;
		str++;
	}
	if (!count)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (count);
}

static char	*next_word(char *str, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		++cursor;
	while ((str[cursor + len] != sep) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != sep) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split(char *str, char sep)
{
	char	**new;
	int		w_count;
	int		i;

	i = 0;
	w_count = count_words(str, sep);
	if (!w_count)
		exit (1);
	new = malloc(sizeof(char *) * (size_t)(w_count + 2));
	if (new == NULL)
		return (NULL);
	while (w_count-- >= 0)
	{
		if (0 == i)
		{
			new[i] = malloc(sizeof(char));
			if (new[i] == NULL)
				return (NULL);
			new[i++][0] = '\0';
			continue ;
		}
		new[i++] = next_word(str, sep);
	}
	new[i] = NULL;
	return (new);
}
