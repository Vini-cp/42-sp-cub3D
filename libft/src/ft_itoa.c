/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:08:55 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:44:40 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	negative_nbr(int *num, int *negative)
{
	*num *= -1;
	*negative = 1;
}

char	*ft_itoa(int num)
{
	int		i;
	int		negative;
	char	*str;

	negative = 0;
	if (num == 0)
		return (str = ft_strdup("0\0"));
	else if (num == -2147483648)
		return (str = ft_strdup("-2147483648\0"));
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (ft_isnegative(num))
		negative_nbr(&num, &negative);
	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
