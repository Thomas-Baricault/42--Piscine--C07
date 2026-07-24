/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:21:52 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/17 10:06:54 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	str_len(char *str)
{
	int	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (*str++)
		length++;
	return (length);
}

int	str_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_push_front(char *str, char c)
{
	char			*new;
	unsigned int	i;
	unsigned int	length;

	length = str_len(str);
	new = malloc(sizeof(char) * (length + 2));
	i = 0;
	while (str && str[i])
	{
		new[i + 1] = str[i];
		i++;
	}
	new[0] = c;
	new[length + 1] = '\0';
	if (str)
		free(str);
	return (new);
}

int	is_valid_base(char *base)
{
	if (str_len(base) < 2)
		return (0);
	while (*base)
	{
		if (str_find("+- \t\n\v\f\r", *base) != -1)
			return (0);
		if (str_find(base + 1, *base) != -1)
			return (0);
		base++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		tmp;
	int		sign;

	if (!(is_valid_base(base_from) && is_valid_base(base_to)))
		return (NULL);
	result = NULL;
	tmp = 0;
	sign = 1;
	while (str_find(" \t\n\v\f\r", *nbr) != -1)
		nbr++;
	while (str_find("+-", *nbr) != -1)
		sign *= (*nbr++ == '+') * 2 - 1;
	while (str_find(base_from, *nbr) != -1)
		tmp = tmp * str_len(base_from) + str_find(base_from, *nbr++);
	if (tmp == 0)
		result = str_push_front(result, base_to[0]);
	while (tmp > 0)
	{
		result = str_push_front(result, base_to[tmp % str_len(base_to)]);
		tmp /= str_len(base_to);
	}
	if (sign == -1 && !(result[0] == '0' && result[1] == '\0'))
		result = str_push_front(result, '-');
	return (result);
}
