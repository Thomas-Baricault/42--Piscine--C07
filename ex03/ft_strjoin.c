/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:49:34 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/07 15:15:42 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	str_len(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*str_cpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	int		i;
	char	*result;
	char	*ptr;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += str_len(strs[i++]);
		if (i < size)
			length += str_len(sep);
	}
	result = malloc(sizeof(char) * (length + 1));
	i = 0;
	ptr = result;
	while (i < size)
	{
		ptr = str_cpy(ptr, strs[i++]);
		if (i != size)
			ptr = str_cpy(ptr, sep);
	}
	result[length] = '\0';
	return (result);
}
