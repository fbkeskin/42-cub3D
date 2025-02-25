/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:28:15 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:13:41 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rgb_helper(int i, const char *str)
{
	while (str[i] != '\0')
	{
		if ((str[i] != ' '))
			return (-999);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (rgb_helper(i, str) == -999)
		return (-999);
	return (sign * result);
}
