/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:37:26 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/07 15:05:28 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		length;

	length = 0;
	while (src[length])
		length++;
	length++;
	result = malloc(sizeof(char) * length);
	while (--length >= 0)
		result[length] = src[length];
	return (result);
}
