/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:05:07 by youhnia           #+#    #+#             */
/*   Updated: 2016/09/30 15:54:39 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*delchar(const char *str, char c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = -1;
	while (s[++i] == c)
		;
	return (s + i);
}

static char			*revstr(const char *str)
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	while (str[++i])
		;
	len = i;
	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (str[++i])
		ret[len - i - 1] = str[i];
	ret[len] = '\0';
	return (ret);
}

static t_split_list	*new_elem(t_split_list *prev,
					char *ptrwrd, char c, int *end)
{
	t_split_list	*new;
	int				i;
	int				len;
	char			*wrd;

	len = -1;
	while (ptrwrd[++len] != c && ptrwrd[len])
		;
	if (ptrwrd[len] == '\0')
		end[0] = 1;
	wrd = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		wrd[i] = ptrwrd[i];
	wrd[len] = '\0';
	new = (t_split_list *)ft_memalloc(sizeof(t_split_list));
	new->wrd = wrd;
	if (end[0] == 0)
		new->ptrnxtwrd = delchar(ptrwrd + len, c);
	if (prev)
		prev->next = new;
	new->next = NULL;
	return (new);
}

static t_split_list	*create_list(const char *str, char c, int *cpt)
{
	t_split_list	*begin;
	t_split_list	*list;
	int				end[1];
	char			*s;

	s = (char *)str;
	list = NULL;
	end[0] = 0;
	while (end[0] == 0)
	{
		if (list == NULL)
		{
			list = new_elem(list, s, c, end);
			begin = list;
		}
		else
			list = new_elem(list, list->ptrnxtwrd, c, end);
		cpt[0]++;
	}
	return (begin);
}

char				**ft_strsplit(const char *s, char c)
{
	t_split_list	*list;
	int				cpt[1];
	char			**tab;
	int				i;
	char			*str;

	str = ft_strdup((char *)s);
	if (str == NULL)
		return (NULL);
	str = revstr(delchar(revstr(delchar(str, c)), c));
	tab = (char **)ft_memalloc(sizeof(char *));
	tab[0] = NULL;
	if (str[0] == '\0')
		return (tab);
	cpt[0] = 0;
	list = create_list(str, c, cpt);
	tab = (char **)ft_memalloc(sizeof(char *) * (cpt[0] + 1));
	i = -1;
	while (++i < cpt[0])
	{
		tab[i] = list->wrd;
		list = list->next;
	}
	tab[i] = NULL;
	return (tab);
}
