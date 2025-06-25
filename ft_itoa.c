/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:47:46 by ogokdas           #+#    #+#             */
/*   Updated: 2025/06/23 12:47:46 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nmb(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nmb;
	int		sign;
	int		len_nmb;

	nmb = n;
	sign = 1;
	if (nmb < 0)
		sign = -1;
	nmb = sign * nmb;
	len_nmb = ft_len_nmb(nmb, sign);
	str = (char *)malloc(sizeof(char) * len_nmb + 1);
	if (!str)
		return (0);
	str[len_nmb] = '\0';
	while (--len_nmb >= 0)
	{
		str[len_nmb] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
