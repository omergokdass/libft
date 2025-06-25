/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:10 by ogokdas           #+#    #+#             */
/*   Updated: 2025/06/23 12:50:10 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, lens1 + 1);
	ft_strlcat(s, s2, lens1 + lens2 + 1);
	return (s);
}
