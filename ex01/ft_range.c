/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:49:17 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/07 15:05:26 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
