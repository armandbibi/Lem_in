/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:59:00 by triou             #+#    #+#             */
/*   Updated: 2018/08/28 19:59:18 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	ft_list_push_back(t_line **blst, char **line, const int fd)
{
	t_line	*elem;
	t_line	*list;
	char	*tmp;

	if (!(elem = (t_line *)malloc(sizeof(*elem))))
		return (-1);
	elem->data = ft_strdup(ft_strchr(*line, '\n') + 1);
	tmp = *line;
	ft_strclr(ft_strchr(*line, '\n'));
	*line = ft_strdup(*line);
	free(tmp);
	elem->fd = fd;
	elem->next = NULL;
	if (!(*blst))
	{
		*blst = elem;
		return (1);
	}
	list = *blst;
	while (list->next)
		list = list->next;
	list->next = elem;
	return (1);
}

static void	ft_lst_del(char **line, t_line **begin_list, t_line *list)
{
	t_line	*prev;

	*line = ft_strdup(list->data);
	if ((prev = *begin_list) == list)
	{
		free(list->data);
		free(list);
		*begin_list = NULL;
		return ;
	}
	while (prev->next != list)
		prev = prev->next;
	prev->next = list->next;
	free(list->data);
	free(list);
}

static int	ft_read_list(t_line **begin_list, const int fd, char **line)
{
	char	*str;
	size_t	len;
	t_line	*list;

	if (fd < 0 || !line)
		return (-1);
	list = *begin_list;
	while (list && list->fd != fd)
		list = list->next;
	if (list && (str = ft_strchr(list->data, '\n')))
	{
		len = str - list->data + 1;
		*line = ft_strsub(list->data, 0, len - 1);
		str = list->data;
		list->data = ft_strsub(list->data, len, ft_strlen(list->data) - len);
		free(str);
		return (1);
	}
	else if (list)
		ft_lst_del(line, begin_list, list);
	else
		*line = ft_strnew(0);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t			ret;
	static t_line	*begin_list = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if ((ret = ft_read_list(&begin_list, fd, line)))
		return (ret);
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n')
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	if (ret < 0)
		return (-1);
	else if (!ret && !(**line))
		return (0);
	else if (!ret && !ft_strchr(*line, '\n'))
		return (1);
	return (ft_list_push_back(&begin_list, line, fd));
}
