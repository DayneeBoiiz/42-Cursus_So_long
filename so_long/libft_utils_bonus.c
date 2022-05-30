/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:40:33 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 11:48:44 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;
	char	*nsrc;

	i = 0;
	nsrc = (char *) src;
	len = ft_strlen(nsrc);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (nsrc[i])
	{
		str[i] = nsrc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	ndest = (unsigned char *) dest;
	nsrc = (unsigned char *) src;
	i = 0;
	if (ndest == NULL && nsrc == NULL)
		return (NULL);
	if (ndest > nsrc)
	{
		while (i < n)
		{
			ndest[n - 1] = nsrc[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (ndest);
}

char	*ft_strjoin_text(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	return (rtn);
}
