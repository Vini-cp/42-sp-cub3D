/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:09:57 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:44:40 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	nb_to_char(char *str, unsigned int nb, int neg)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	str[i] = (nb % 10) + '0';
	if (neg)
	{
		str[i] = '-';
		str[i + 1] = '\0';
	}
	else
		str[i] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char			str[12];
	int				neg;
	int				i;
	unsigned int	nb;

	neg = ft_isnegative(n);
	i = 0;
	if (neg)
		nb = n * (-1);
	else
		nb = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		nb_to_char(str, nb, neg);
		ft_strrev(str);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
