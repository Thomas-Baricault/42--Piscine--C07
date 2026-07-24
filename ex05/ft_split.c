/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:01:40 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:53 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_contains(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char	*str_dup(char *begin, char *end)
{
	char	*result;

	result = malloc(sizeof(char) * (end - begin + 1));
	result[end - begin] = '\0';
	while (--end >= begin)
		result[end - begin] = *end;
	return (result);
}

int	count_words(char *str, char *charset)
{
	char	*ptr;
	int		count;

	count = 0;
	while (*str)
	{
		ptr = str;
		while (*ptr && str_contains(charset, *ptr) == 0)
			ptr++;
		if (ptr - str > 0)
			count++;
		str = ptr;
		if (*str)
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*ptr;
	int		i;

	i = count_words(str, charset);
	result = malloc(sizeof(char *) * (i + 1));
	result[i] = NULL;
	i = 0;
	while (*str)
	{
		ptr = str;
		while (*ptr && str_contains(charset, *ptr) == 0)
			ptr++;
		if (ptr - str > 0)
			result[i++] = str_dup(str, ptr);
		str = ptr;
		if (*str)
			str++;
	}
	return (result);
}
